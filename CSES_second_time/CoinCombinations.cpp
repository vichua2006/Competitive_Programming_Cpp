/*

dp[i][j] = dp[i-1][j] + dp[i-1][j-wi] + dp[i-1][j-2wi] +...+ dp[i-1][j-kwi]

dp[i][j-wi] = dp[i-1][j-wi] + dp[i-1][j-2wi] +....+ dp[i-1][j-kwi]

so dp[i][j] = dp[i-1][j] + dp[i][j-wi]
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN],w[101];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> w[i];
    dp[0] = 1;
    for (int i=1;i<N+1;i++){
        for (int j=w[i];j<=M;j++){
            dp[j] += dp[j-w[i]];
            dp[j] %= MOD;
        }
    }
    cout << dp[M] << '\n';
    return 0;
}