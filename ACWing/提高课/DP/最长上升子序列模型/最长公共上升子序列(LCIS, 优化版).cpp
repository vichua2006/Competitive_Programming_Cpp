/*

continuation of the first LCIS

more often than not, optimization to dp problems occur as changes to the code rather than the general solution (well, in most cases)
such as the equation simplification in unbounded knapsack, or here (similar to CCC 2019 S4, and some USACO dp problem), to 
maintain the min/max value in O(1) instead of looping over the whole thing to find it

(refer to the first LCIS file for below)
realize on line 54, the condition 

    if (b[k] < b[j]){...}

can be rewritten as 

    if (b[k] < a[i]){...}

since that loop for k happends only when a[i] == b[j]

notice that now, this condition is largely independent of the variable j (k < j)
and since a[i] remains the same for the entire row (entire loop of j) we can simply maintain the value of max(dp[i - 1][k] + 1)
instead of looping over to find it each time

there also should be better space optimizations, but it is not as simple and is not required, and thus was not implemented
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 3e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int a[maxN], b[maxN];
int dp[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> a[i];
    for (int i=1;i<N+1;i++) cin >> b[i];

    // init: dp[0][j] for all j = 0
    for (int i=1;i<N+1;i++){
        // the largest value of dp[i - 1][k] + 1
        int msf = 1;
        for (int j=1;j<N+1;j++){
            dp[i][j] = dp[i - 1][j];
            if (a[i] == b[j]) dp[i][j] = max(dp[i][j], msf);
            // placed last, as we should only consider msf from the first j - 1
            // values when computing j
            if (b[j] < a[i]) msf = max(msf, dp[i - 1][j] + 1);
        }
    }

    int res = 0;
    for (int i=1;i<N+1;i++) res = max(res, dp[N][i]);

    cout << res << '\n';

    return 0;
}