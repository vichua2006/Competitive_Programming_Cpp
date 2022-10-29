/*

the difference between this problem and the general "count how many ways to make up this value"
is that this one has a size restriction, and we do not know the wanted value

(this is also similar to the counting number of shorest/longest paths on a graph problems on cses,
will probably get to that around october)

let dp[i][j] be the regular 0-1 knapsack, and let cnt[i][j] denote the number of ways to achieve the value of dp[i][j] 
when only considering the first i items and using no more than j unites of space

the value of dp[i][j] can be achieve either from d[i - 1][j] or dp[i - 1][j - s] + v, so 
if dp[i][j] = d[i - 1][j], then cnt[i][j] = cnt[i - 1][j]
if dp[i][j] = dp[i - 1][j - s] + v, then cnt[i][j] = cnt[i - 1][j - s];

and if dp[i][j] equals both, then cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j - s]

both can be optimized to 1-d

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
ll dp[maxN], cnt[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    // init
    // by definition, there is only 1 way to obtain dp[0][j] for any j, which is picking nothing
    for (int i=0;i<M+1;i++) cnt[i] = 1;
    for (int i=0;i<N;i++){
        int s, v; cin >> s >> v;
        for (int j=M;j>=s;j--){
            int val = dp[j];
            dp[j] = max(dp[j], dp[j - s] + v);
            if (dp[j] == val && dp[j] == dp[j - s] + v) cnt[j] += cnt[j - s];
            else if (dp[j] == dp[j - s] + v) cnt[j] = cnt[j - s];

            cnt[j] %= MOD;
        }
    }

    cout << cnt[M] << '\n';

    return 0;
}