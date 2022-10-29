/*

regular knapsack with additional costs

for example, this one has both size and weight

the simple solution is to add an addtional dimension to the dp

dp[i][j][k] will denote the maximum value that can be achieved by considering the first i objects
and using no more than j units of space and k units of weight

time : O(N * M * K) ~ 1e6

same logic, we either choose the ith object or we don't

therefore, dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - si][k - wi] + vi)
since the computation only uses values from the previous layer, this can be optimized into 2-d dp


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M, K;
int dp[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> K;
    for (int i=0;i<N;i++){
        int s, w, v; cin >> s >> w >> v;
        for (int j=M;j>=s;j--){
            for (int k=K;k>=w;k--){
                dp[j][k] = max(dp[j][k], dp[j - s][k - w] + v);
            }
        }
    }

    cout << dp[M][K] << '\n';

    return 0;
}