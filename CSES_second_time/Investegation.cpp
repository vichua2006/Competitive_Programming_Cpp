#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
ll N,M,rtc[maxN],minr[maxN],maxr[maxN],dis[maxN];
bool visited[maxN];
vector<ar<ll,2>> g[maxN];
vector<ll> gmin[maxN],tp;

void dijkstra(){
    priority_queue<ar<ll,3>,vector<ar<ll,3>>,greater<ar<ll,3>>> pq;
    for (int i=1;i<N+1;i++) dis[i] = INF;
    dis[1] = 0;
    // cost, curr node, pre node;
    pq.push({0,1,0});
    while (pq.size()){
        ar<ll,3> node = pq.top();pq.pop();
        ll c = node[0],v = node[1],pre = node[2];
        if (visited[v]){
            // also a edge of one of the shortest paths
            if (c==dis[v]){
                gmin[pre].push_back(v);
            }
        } else {
            // the first to appear must be one of the shortest path
            visited[v] = 1;
            gmin[pre].push_back(v);
            for (ar<ll,2> a: g[v]){
                ll nc = a[0],nv = a[1];
                // HAS TO BE A FREAKING >=, not >. That allows multiple routes to exists
                // I made the exact same mistake as last time
                if (dis[nv] >= c+nc){
                    dis[nv] = c+nc;
                    pq.push({c+nc,nv,v});
                }
            }
        }
    }
    return;
}

void dfs(ll curr){
    // dijkstra creates a DAG;
    visited[curr] = 1;
    for (ll a:gmin[curr]){
        if (!visited[a]) dfs(a);
    }
    tp.push_back(curr);
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
    dijkstra();
    memset(visited,0,sizeof(visited));
    for (int i=1;i<N+1;i++){
        if (!visited[i]) dfs(i);
    }
    reverse(tp.begin(),tp.end());
    //initialization
    memset(minr,0x3f,sizeof(minr)),memset(maxr,-0x3f,sizeof(maxr));
    rtc[1] = 1,minr[1] = 0,maxr[1] = 0;
    for (int v:tp){
        for (int a:gmin[v]){
            rtc[a] = (rtc[a]+rtc[v])%MOD;
            minr[a] = min(minr[a],minr[v]+1);
            maxr[a] = max(maxr[a],maxr[v]+1);
        }
    }
    cout << dis[N] << ' ' << rtc[N] << ' ' << minr[N] << ' ' << maxr[N] << '\n';
    return 0;
}