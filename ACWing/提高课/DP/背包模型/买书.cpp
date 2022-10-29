/*

this is a unbounded knapsack in disguse

dp[i][j] denotes the number of ways to buy books when considering only the first i books and using j units of currency

therefore, dp[i][j] = dp[i - 1][j] + dp[i - 1][j - c] + dp[i - 1][j - 2c] +...+ dp[i - 1][j - kc]

= dp[i - 1][j] + dp[i][j - c]

same simplification logic as unbounded knapsack

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    vector<int> c = {10, 20, 50, 100};
    // one method: buy nothing
    dp[0] = 1;
    for (int i=0;i<4;i++){
        for (int j=c[i];j<N+1;j++) dp[j] += dp[j - c[i]];
    }

    cout << dp[N] << '\n';

    return 0;
}