/*

unbounded knapsack, basically

dp[i][x] = set of all ordered ways to achieve x using first i coins, unlimtied coins
stored value is set size (count)

so dp[i][x] = dp[i-1][x] + dp[i-1][x-ci] + dp[i-1][x-2ci] +....+ dp[i-1][i-kci]

notice that dp[i][x-ci] = dp[i-1][x-ci] + dp[i-1][x-2ci] + dp[i-1][x-3ci] +....+ dp[i-1][i-kci]

therefore dp[i][x] = dp[i-1][x] + dp[i][x-ci]

this could then be optimized into 1d dp since it only uses dp[i-1] for dp[i]
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN],c[101];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> c[i];
    // whatever coins you are using, you can always make 0
    dp[0] = 1;
    for (int i=1;i<N+1;i++){
        // j needs to be bigger than ci to be valid anyways
        for (int j=c[i];j<M+1;j++){
            dp[j] = (dp[j]+dp[j-c[i]])%MOD;
        }
    }
    cout << dp[M] << '\n';
    return 0;
}