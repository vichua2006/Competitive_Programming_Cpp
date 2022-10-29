/*

dp, but it only uses one state
dp[i] denotes the maximum value achieve by considering only the first i stores

dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int T, N;
int dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T -- ){
        cin >> N;
        memset(dp, 0, sizeof(dp));
        for (int i=1;i<N+1;i++){
            int a; cin >> a;
            if (i == 1) dp[i] = a;
            else dp[i] = max(dp[i - 1], dp[i - 2] + a);
        }

        cout << dp[N] << '\n';
    }

    return 0;
}