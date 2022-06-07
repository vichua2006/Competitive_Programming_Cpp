// k shortest paths, using dijkistra?
// so, use n by k array for distance. since, if visited array is not implimented, dijkstra actaully
// updates a value several times, but discards all but the smallest one. this time we need to discard all but the
// the first k smallest ones. we use the n by k array where the n in node and k are the smallest k values sorted in 
// decreasing order, with all the cells initially being INF.
// Then after each round of updating, we sorted the array of those updated nodes, since k <= 10, this should be within limits.
// figure out the rest tomorrow.
// so just a dijkstra that stores all values

#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pii pair<ll,ll>
const ll INF = 1e15, maxN = 1e5+1;

ll n,m,k, dis[maxN][10];
vector<pii> g[maxN];
priority_queue<pii> q;

void solve(){
    for (int i=0;i<maxN;i++){
        for (int j=0;j<10;j++){
            dis[i][j] = INF;
        }
    }

    dis[1][0] = 0;
    q.push({0,1});
    while(!q.empty()){
        // because we can't relieably access the distance from l to 1, we use a dummy variable to keep tract of it
        ll v = q.top().second, d = abs(q.top().first); q.pop();
        if (dis[v][k-1] < d) continue;
        // checks if node v already has k shortest paths, prevent pointless calculations as the surrounding nodes will
        // have values updated by the previous k paths
        for (pii a: g[v]){
            ll u = a.second, w = abs(a.first);
            if (dis[u][k-1] > d+w){
                dis[u][k-1] = d+w;
                q.push({-(d+w),u});
                sort(dis[u],dis[u]+k);
            }
        }
    }

    for (int i=0;i<k;i++) cout << dis[n][i] << ' ';
    return;
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        g[a].push_back({c,b});
    }
    solve();
    return 0;
}