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

const int maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,M,dp[maxN][maxM];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        ll a; cin >> a;
        if (a){
            if (i==1) dp[i][a] = 1;
            else dp[i][a] = (dp[i-1][a-1]+dp[i-1][a]+dp[i-1][a+1])%MOD;
        } else {
            for (int j=1;j<M+1;j++){
                if (i==1) dp[i][j] = 1;
                else{
                    dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=M;i++) ans = (ans+dp[N][i])%MOD;
    cout << ans << '\n';
    return 0;
}