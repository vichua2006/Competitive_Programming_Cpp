// find all SCC, sum up the values of the SCC, construct SCC into DAG and do dp on it
// write a v2 sometime
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,M,scc[maxN],coins[maxN],v[maxN],dp[maxN];
vector<ll> tp;
// to avoid duplicate edges later on
set<ll> g[maxN],gscc[maxN],ginv[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(ll curr,set<ll> gg[maxN], ll k,bool do_tp){
    // the scc array is being doubled as a visited, twice actually
    if (scc[curr] > 0) return;
    scc[curr] = k;
    for (ll a:gg[curr]){
        dfs(a,gg,k,do_tp);
    }
    if(do_tp) tp.push_back(curr);
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> coins[i];
    for (int i=0;i<M;i++){
        ll a,b; cin >> a >> b;
        g[a].insert(b);
        ginv[b].insert(a);
    }
    for (int i=1;i<N+1;i++){
        if (!scc[i]) dfs(i,g,1,true);
    }
    // clear scc for its actual purpose
    memset(scc,0,sizeof(scc));
    ll group = 0;
    while(tp.size()){
        int node = tp.back(); tp.pop_back();
        if (!scc[node]){
            group += 1;
            dfs(node,ginv,group,false);
        }
    }
    // create a new graph
    for (int i=1;i<N+1;i++){
        v[scc[i]] += coins[i];
        for (ll a:g[i]){
            // make sure that the nodes are of different components
            if (scc[i]!=scc[a]) gscc[scc[i]].insert(scc[a]);
        }
    }
    // tp new graph
    tp.clear();
    memset(scc,0,sizeof(scc));
    for (int i=1;i<group+1;i++){
        if (!scc[i]) dfs(i,gscc,1,true);
    }
    reverse(tp.begin(),tp.end());
    // basically a longest path dp idea, with the edge from u to a is weighted v[u]
    // this means that in dp[x], v[x] is excluded, so we need to add that back when checking on that last loop
    for (int u:tp){
        for (int a:gscc[u]){
            dp[a] = max(dp[a],v[u]+dp[u]);
        }
    }
    ll ans = 0;
    // v[i] needs to be added back
    for (int i=1;i<group+1;i++) ans = max(dp[i]+v[i],ans);
    cout << ans << '\n';
    return 0;
}