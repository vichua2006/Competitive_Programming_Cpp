// dp with topological sort
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN],ans = 0;
// outd[i] represents whether the out degree of node i > 0
bool visited[maxN],outd[maxN],ind[maxN];
vector<int> g[maxN],tp;


void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int curr){
    visited[curr] = true;
    for (int a:g[curr]){
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
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        outd[a] = true,ind[b] = true;
    }
    // do tp sort
    for (int i=1;i<N+1;i++){
        if (!visited[i]) dfs(i);
    }
    reverse(tp.begin(),tp.end());

    for (int i=1;i<N+1;i++){
        // weird dp equation here
        int v = tp[i-1];
        for (int a:g[v]){

        }
    }
    for (int i=1;i<N+1;i++){
        if (!outd[i]) ans = (ans + dp[i])%MOD;
    }
    cout << ans << '\n';
    return 0;
}