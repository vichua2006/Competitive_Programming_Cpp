/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN],p[maxN];
bool visited[maxN];
vector<int> g[maxN],tp;

void dfs(int curr){
    visited[curr] = 1;
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
        int a,b; cin>> a >> b;
        g[a].push_back(b);
    }
    for (int i=1;i<N+1;i++){
        if (!visited[i]) dfs(i);
    }
    memset(dp,-0x3f,sizeof(dp));
    reverse(tp.begin(),tp.end());
    dp[1] = 1,p[1] = 1;
    for (int v:tp){
        for (int a:g[v]){
            if (dp[a]<dp[v]+1) dp[a] = dp[v]+1,p[a] = v;
        }
    }
    if (dp[N] < 0){
        cout << "IMPOSSIBLE\n";
    } else{
        cout << dp[N] << '\n';
        vector<int> ans;
        int temp = N;
        while (temp!=1) ans.push_back(temp), temp = p[temp];
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        for (int a:ans) cout << a << ' ';
    }
    return 0;
}