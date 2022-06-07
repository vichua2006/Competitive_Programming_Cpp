#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
ll N,M,dis[maxN][2];
bool visited[maxN][2];
vector<ar<ll,2>> g[maxN];

void dikstra(){
    priority_queue<ar<ll,3>,vector<ar<ll,3>>,greater<ar<ll,3>>> pq;
    for (int i=1;i<N+1;i++) dis[i][0] = INF,dis[i][1] = INF;
    dis[1][0] = 0,dis[1][1] = 0;
    pq.push({0,1,0});
    while (pq.size()){
        ar<ll,3> node = pq.top();pq.pop();
        ll c = node[0],v = node[1],t = node[2];
        if (visited[v][t]) continue;
        visited[v][t] = 1;
        for (ar<ll,2> a:g[v]){
            ll nc = a[0],nv = a[1];
            if (dis[nv][t] > c+nc){
                dis[nv][t] = c+nc;
                pq.push({c+nc,nv,t});
            }
            if (t==0&&dis[nv][t+1] > c+nc/2){
                dis[nv][t+1] = c+nc/2;
                pq.push({c+nc/2,nv,t+1});
            }
        }
    }
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        ll a,b,c; cin >> a >> b >> c;
        g[a].push_back({c,b});
    }
    dikstra();
    cout << dis[N][1] << '\n';
    return 0;
}