#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5+1,MOD = 1e9+7;

int N,M,dp[maxN];
bool visited[maxN];
vector<int> g[maxN],tp;

void dfs(int curr){
    visited[curr] = 1;
    for (int a:g[curr]){
        if (!visited[a]){
            dfs(a);
        }
    }
    tp.push_back(curr);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i=1;i<N+1;i++){
        if (!visited[i]) dfs(i);
    }
    reverse(tp.begin(),tp.end());
    dp[1] = 1;
    for (int v:tp){
        for (int a:g[v]) dp[a] = (dp[a]+dp[v])%MOD;
    }
    cout << dp[N] << '\n';
    return 0;
}