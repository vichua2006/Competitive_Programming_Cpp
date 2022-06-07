// graph dp, how many ways to reach N
// needs to do dp in topological sorted order to prevent miscounting paths
// e.g. if node 3 was used in push dp, a later node might come back and update node 3 again, but those new paths will never be included
// also, yes, this uses push dp, although pull dp has no difference, it requires the edges to be revered
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,M,dp[maxN],visited[maxN];
vector<int> g[maxN], tp;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int curr){
    // topological sort
    visited[curr] = 1;
    for (int a:g[curr]){
        if (visited[a] != 2) dfs(a);
    }
    visited[curr] = 2;
    tp.push_back(curr);
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
    }
    // do top sort, get correct ordering for dp
    for (int i=1;i<N+1;i++){
        if (visited[i] != 2) dfs(i);
    }
    reverse(tp.begin(),tp.end());
    // theres one way to get to node 1
    dp[1] = 1;
    for (int v: tp){
        for (int a:g[v]) dp[a] = (dp[a]+dp[v])%MOD;
    }
    cout << dp[N] << '\n';
    return 0;
}