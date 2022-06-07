/*

dp[i][j] denotes the minimum sum of the sizes for catching the first j snakes with i changes
therefore,

    dp[i][j] = min(dp[i-1][j-1] + max(w[j]), dp[i-1][j-2] + 2*max(w[j], w[j-1]), ... , dp[i-1][i-1] + (j-i)*max(w[j], w[j-1], ... , w[i]))
    (switch to a bigger net after the j-1 snake and catch up to j, switch after j-2 and up to j, 
    ... switch at i-1 (which is the limit) and catch from i to j)

again, the runtime is O(N^4), but the maximum max(w[j...i]) can simply be maintained instead of
repeatedly computed with a loop. This yields O(N^3) runtime

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 4e2 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, K;
// this could potentially be optimized to O(N) space since it only uses the previous row
// in which case it would need to update right to left instead.
ll dp[maxN][maxN], w[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("snakes");

    cin >> N >> K;
    ll msf = 0;
    memset(dp, 0x3f, sizeof(dp));
    for (int i=1;i<N+1;i++) cin >> w[i], msf = max(msf, w[i]), dp[0][i] = i*msf;
    for (int i=1;i<K+1;i++){
        for (int j=1;j<N+1;j++){
            msf = 0;
            for (int k=j-1;k>=i-1;k--){
                msf = max(msf, w[k+1]);
                dp[i][j] = min(dp[i][j], dp[i-1][k] + (j-k)*msf);
            }
        }
    }
    ll sum = 0;
    for (int i=1;i<N+1;i++) sum += w[i];
    cout << dp[K][N] - sum << '\n';
    return 0;
}