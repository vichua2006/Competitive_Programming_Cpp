/*

dp[i][j] = number of ways to build the tower to ith layer with the ith layer
vertically (split in the middle) seperated into j pieces (so j=0 or j=1)

since this only records the vertical seperation state for each layer,
casework will have to be done during state transitions to account for the
different possible horizontal seperations for each situation (consult pdf of the same folder)

in the end, we obtain: 

    dp[i][0] = 2*dp[i-1][0] + dp[i-1][1]
    dp[i][1] = dp[i-1][0] + 4*dp[i-1][1]

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int T, N;
ll dp[maxN][2];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T--){
        cin >> N;
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1, dp[1][1] = 1;
        for (int i=2;i<N+1;i++){
            dp[i][0] = (2*dp[i-1][0] + dp[i-1][1])%MOD;
            dp[i][1] = (dp[i-1][0] + 4*dp[i-1][1])%MOD;
        }
        cout << (dp[N][0] + dp[N][1])%MOD << '\n';
    }
    return 0;
}