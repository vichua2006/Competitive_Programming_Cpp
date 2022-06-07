// basic dp problem

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll maxN = 1e6+1, MOD = 1e9+7;

ll N,dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    // initialization is different
    for (int i=1;i<7;i++){
        for (int j=1;j<i;j++){
            dp[i] += dp[i-j];
        }
        dp[i] += 1;
    }
    for (int i=7;i<N+1;i++) for (int j=1;j<7;j++) dp[i] = (dp[i] + dp[i-j])%MOD;
    cout << dp[N] << '\n';
    return 0;
}