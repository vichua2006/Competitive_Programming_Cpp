//given a DAG, calculate the longest path from 1 to N
// from experoence of game routes, this also uses tp sort + DP
// use push dp, and record parents
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN],p[maxN];
bool visited[maxN];
vector<int> g[maxN],tp;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

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
        int a,b; cin >> a >> b;
        g[a].push_back(b);
    }
    // do tp sort
    for (int i=1;i<N+1;i++){
        if (!visited[i]) dfs(i);
    }
    reverse(tp.begin(),tp.end());
    // dp[i] denotes the number of cities in the largest route from 1 to i
    // it is set to -INF to prevent situations where it's impossible go from 1 to N but N still gets updated,
    // causing an runtime error; since N<=1e5, it has to start on 1 to even achieve a positive value. Hence "if (dp[N] > 0)"
    for (int i=0;i<N+1;i++) dp[i] = -INF;
    dp[1] = 1,p[1] = -1;
    for (int v:tp){
        for (int a:g[v]){
            if (dp[a] < dp[v] + 1){
                // update new value and parent node
                // feels like a dijkstra's
                dp[a] = dp[v] + 1, p[a] = v;
            }
        }
    }
    if (dp[N] > 0){
        cout << dp[N] << '\n';
        int n = N;
        vector<int> ans;
        while (n != -1){
            ans.push_back(n);
            n = p[n];
        }
        for (auto a = ans.end()-1; a >= ans.begin(); a--) cout << *a << ' ';
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}