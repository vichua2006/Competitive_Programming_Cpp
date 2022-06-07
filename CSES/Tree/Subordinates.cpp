//counting the number of nodes in each subtree, recursion seems easier to implement
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,dp[maxN];
vector<int> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int curr){
    for (int a: g[curr]){
        dfs(a);
        dp[curr] += dp[a] + 1;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=2;i<N+1;i++){
        int a; cin >> a;
        g[a].push_back(i);
    }
    dfs(1);
    for (int i=1;i<N+1;i++) cout << dp[i] << (i == N?'\n':' ');
    return 0;
} 