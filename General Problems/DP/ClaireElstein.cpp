// my first DP graph problem, and it's a problem about some girl playing eroge
// anyways, given a DAG, compute the sum of the lengths of all paths from 
// a vertex with indegree 0 to a vertex with outdegree 0.
//
// eeh.. TLE'd 

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define array

const int maxN = 1e5 + 1, MOD = 1e9 + 7;

ll n,m,dp[maxN],ans=0;
// whether this node leads to another node; whether a node leads to this node
bool outd[maxN], ind[maxN];
vector<ll> g[maxN];

void solve(ll curr,ll s){
    // dfs search from each node with indegree of 0
    for (ll a: g[curr]){
        //  sum of all length of paths to x = sum of all length of curr + 1
        dp[a] += (s + 1)%MOD;
        solve(a,s+1);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll a,b; cin >> a >> b;
        // there's a node leading to b ; a leads to a node
        g[a].push_back(b), ind[b] = true, outd[a] = true;
    }
    for (int i=1;i<n+1;i++){
        if(!ind[i]) solve(i,0);
    }
    for (int i=1;i<n+1;i++){
        if(!outd[i]) ans = (ans + dp[i])%MOD;
    }
    cout << ans << '\n';
    return 0;
}
