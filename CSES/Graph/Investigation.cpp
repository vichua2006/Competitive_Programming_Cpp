// appearently dp combined with dijkstra
// find miminum path, number of such paths, longest of such path, and shortest of such paths
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,M,dis[maxN],dp[3][maxN];//0: number of paths 1: shortest path 2: longest path
bool visited[maxN];
// two adjancent list. one for dijkstra, the other used for dp purposes
vector<ar<ll,2>> g1[maxN];
vector<ll> g2[maxN],tp;
priority_queue<ar<ll,3>,vector<ar<ll,3>>,greater<ar<ll,3>>> pq;


void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    memset(visited,0,sizeof(visited));
    dis[1] = 0;
    pq.push({0,1,0});
    while(pq.size()){
        ar<ll,3> node = pq.top(); pq.pop();
        ll c = node[0], v = node[1], pre = node[2];
        if (c > dis[v]) continue;
        // dijkstra's ensures the node that pops out is definitely the shortest path to that node
        // checks if it matches with current shortest path length length
        // it should have been updated when it was pushed into pq
        if (c == dis[v]){
            // record edges used by shortest paths
            g2[pre].push_back(v);
            // to prevent duplicating edges and causing incorrect answer to second question and causing TLE
            // if you have been here already, only record the new edge; if it first time, then continue like regular dijkstra
            if (visited[v]) continue;
            visited[v] = true;
        }
        for (ar<ll,2> a:g1[v]){
            ll nc = a[0], nv = a[1];
            // it needs to be >= here, not the usual > since that prevents the generation of multiple shortest paths
            if (dis[nv] >= dis[v] + nc){
                dis[nv] = dis[v] + nc;
                pq.push({dis[nv],nv,v});
            }
        }
    }
}

void dfs(ll curr){
    // topological sort; graph is DAG
    visited[curr] = 1;
    for (ll a:g2[curr]){
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
        g1[a].push_back({c,b});
    }
    dijkstra();
    // dijkstra produces a DAG. We can now do a tp sort on it
    memset(visited,0,sizeof(visited));
    for (int i=1;i<N+1;i++){
        if (!visited[i]) dfs(i);
    }
    reverse(tp.begin(),tp.end());
    // do three dp
    memset(dp[1],0x3f,sizeof(dp[1]));
    dp[0][1] = 1;
    dp[1][1] = 0;
    dp[2][1] = 0;
    for (ll v:tp){
        for (ll a:g2[v]){
            // push dp, do all three at the same time, saves some code
            dp[0][a] = (dp[0][a]+dp[0][v])%MOD;
            dp[1][a] = min(dp[1][a],dp[1][v] + 1);
            dp[2][a] = max(dp[2][a],dp[2][v] + 1);
        }
    }
    cout << dis[N] << ' ' << dp[0][N] << ' ' << dp[1][N] << ' ' << dp[2][N] << '\n';
    return 0;
}