// create two arrays, one for distance without coupon, one with.
// for each edge, record whether the coupon is used, if not,
// we will produce two tuples that gets pushed into the pq, on using the coupon, and one without
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int maxN = 1e5 + 1;

// dis[false] = coupon not used, dis[true] = used
ll n,m,dis[maxN][2];
// it is questionable whether visited still works in this situation
// update: yep it does, and is necessary, think about why?
bool visited[maxN][2];
vector<ar<ll,2>> g[maxN];

void solve(){
    priority_queue<ar<ll,3>,vector<ar<ll,3>>,greater<ar<ll,3>>> pq;
    memset(dis,0x3f,sizeof dis);
    dis[1][0] = 0, dis[1][1] = 0;
    pq.push({0,1,0});
    while(pq.size()){
        ar<ll,3> node = pq.top(); pq.pop();
        ll d = node[0], v = node[1], t = node[2];
        if (visited[v][t]) continue;
        visited[v][t] = true;
        for (ar<ll,2> a: g[v]){
            ll nd = a[0], nv = a[1];
            // dis[v] and c are the same thing
            if (dis[nv][t] > d + nd){
                dis[nv][t] = d + nd;
                pq.push({d+nd,nv,t});

                
            }
            // if coupon was not used, use it on this edge
            if (!t){
                if (dis[nv][1] > d + nd/2){
                    dis[nv][1] = d + nd/2; 
                    pq.push({d + nd/2,nv,1});
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll a,b,c; cin >> a >> b >> c;
        g[a].push_back({c,b});
    }
    solve();
    cout << dis[n][1] << '\n';
    return 0;
}