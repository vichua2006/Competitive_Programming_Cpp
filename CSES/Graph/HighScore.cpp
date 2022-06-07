// my first bellman-ford problem
// the algorithm goes through n rounds, and is mathematically correct because it basically starts out at node 
// 1 and expands outwards and updates surrounding nodes with all possible edges and keeps the minimum distance 
// so it guarentees that all nodes will be at their minimum distance, so if nodes still update on the Nth round,
// it means that there is an negative cycle in the graph
// for this question, replace the word minimum with maximum
// to determine whether we go from one through the cycle to N (whether the cycle can actually be used)
// perform dfs from 1 to all and from N to all, record connectivity, and check all node updated on the Nth round of Bellman-ford
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2500 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,M,dis[maxN],ans;
bool con1[maxN], conN[maxN];
vector<ar<ll,3>> E;
vector<ll> g1[maxN],g2[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(ll curr,vector<ll> g[maxN],bool visited[maxN]){
    for (ll a:g[curr]){
        if (!visited[a]){
            visited[a] = true;
            dfs(a,g,visited);
        }
    }
}

void BMF(){
    for (ar<ll,3> e:E){
        ll a = e[0], b = e[1], c = e[2];
        dis[b] = max(dis[b],dis[a] + c);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        ll a,b,c; cin >> a >> b >> c;
        // reverse edges to perform dfs on N
        g1[a].push_back(b), g2[b].push_back(a);
        E.push_back({a,b,c});
    }
    // check connectivitiy
    con1[0] = true, conN[N] = true;
    dfs(1,g1,con1),dfs(N,g2,conN);
    // can't be 0, has to be -INF
    memset(dis,-0x3f, sizeof(dis));
    dis[1] = 0;
    // go through n-1 rounds
    for (int i=0;i<N-1;i++) BMF();
    for (ar<ll,3> e:E){
        ll a = e[0], b = e[1], c = e[2];
        if (dis[b] < dis[a] + c){
            if (con1[b]&&conN[b]){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << dis[N] << '\n';
    return 0;
}