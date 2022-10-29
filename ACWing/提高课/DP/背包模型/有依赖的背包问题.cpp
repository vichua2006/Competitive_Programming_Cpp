/*

this is essentially dp on tree with elements of knapsack mixed in

dp[i][j] denotes the maximum possible value achieve when considering the subtree with node i as root and using no more than j units of space
(and because we are choosing from the children of the node, the item the node represents must be chosen itself)

let s[i] denote the size of the ith item, and let g[i] denote the children of i

thus, to compute dp[i][j], we must compute the maximum value that can be achieved by choosing nodes amongst the rest of the subtree
(which corresponds to choosing amongst the children) whilst using no more than j - s[i] units of space

this can be then viewed as group knapsack computation (very similar to 机器分配 in the same folder), 
since each child can yield up to M + 1 different "items" (using 0/1/2/ ... /M units of space)

the kth "item" of child c, has a size of k and a value of dp[c][k]


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M, r;
int s[maxN], v[maxN];
int dp[maxN][maxN];
vector<int> g[maxN];

void dfs(int u){
    // space that will remain after the current item is chosen
    int K = M - s[u];
    for (int a : g[u]){
        dfs(a);
        // group knapsack dp
        // optimized to 1-d, so in reverse order
        for (int i=K;i;i--){
            // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - k] + arr[i][k])
            for (int j=0;j<=i;j++) 
                dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[a][j]);
        }
    
    }
    // add the value of the uent item 
    for (int i=M;i>=s[u];i--) dp[u][i] = dp[u][i - s[u]] + v[u]; 
    // set anything less than s[curr] to 0 as the current item cannot be chosen
    for (int i=0;i<s[u];i++) dp[u][i] = 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        cin >> s[i] >> v[i];
        int a; cin >> a;
        if (a == -1){
            r = i;
            continue;
        }
        g[a].push_back(i);
    }
    dfs(r);

    cout << dp[r][M] << '\n';

    return 0;
}