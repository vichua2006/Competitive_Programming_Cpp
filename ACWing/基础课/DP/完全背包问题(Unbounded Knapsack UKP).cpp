/* 
similar to 01 knapsack
dp[i][j] = max using j space and the first i items
for some item i, we can chose to pick it 0 times, 1 time, 2,3,...k, where k = floor(j/v[i])
so we basically just insert another for loop in the 01 knapsack code, and we are done
... naive
with N<=1000 and complexity of O(N^3) (3 loops) ~ 1e9 -> TLE
let v denote v[i], w denote w[i]
reconsider equation of dp[i][j]:

    dp[i][j] = max(dp[i-1][j], dp[i-1][j-v]+w, dp[i-1][j-2v]+2w....dp[i-1][j-kv]+kw)

we want to see if some of these parts have already been calculated
consider the equation for dp[i][j-v]:

    dp[i][j-v] = max(dp[i-1][j-v], dp[i-1][j-2v]+w, dp[i-1][j-3v]+2w....dp[i-1][j-kv]+(k-1)w)

comapring the two side my side:

1.    max(dp[i-1][j], dp[i-1][j-v]+w, dp[i-1][j-2v]+2w....dp[i-1][j-kv]+kw)
2.    max(            dp[i-1][j-v], dp[i-1][j-2v]+w,......dp[i-1][j-kv]+(k-1)w)

notice that the latter part of 1. is just 2. + w

we see that 1. = max(dp[i-1][j],max(dp[i-1][j-v]+w, dp[i-1][j-2v]+2w....dp[i-1][j-kv]+kw))) 
               = max(dp[i-1][j],max(dp[i-1][j-v], dp[i-1][j-2v]+w....dp[i-1][j-kv]+(k-1w)) + w)
               = max(dp[i-1][j],2. + w)

therefore, dp[i][j] = max(dp[i-1][j],dp[i][j-v]+w)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN][maxN],v[maxN],w[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> v[i] >> w[i];
    // initialization: 
    // dp[0][0] = 0;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            dp[i][j] = max(dp[i-1][j],(j-v[i]>=0?dp[i][j-v[i]]+w[i]:0));
        }
    }
    cout << dp[N][M] << '\n';
    return 0;
}