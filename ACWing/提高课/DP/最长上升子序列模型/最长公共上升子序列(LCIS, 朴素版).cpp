/*

this problem is the combination of the LIS and LCS problem, longest common increasing subsequence

the state representation is the indeed a combination of both

let dp[i][j] represent the all common increasing subsequences when considering the first i numbers from a 
and the first j numbers from b (LCS), with the sequence ending in b[j] (LIS, and it could also be a[i] instead), 
and the stored value the length of the longest sequence

thus, there could be two possible "last step"s (similar to LCS, but b[j] is fixed, so it leaves only a[i])
1. a[i] not present in the solution, and
2. a[i] IS present in the solution

1. is the equivalent of the LCIS considering only the first i - 1 numbers from a and j from b, and ending in b[j],
and thus: dp[i - 1][j]

2. is only applicable if a[i] == b[j] (because it is last in the sequence), and we thus want to find the LCIS when only considering
the first i - 1 from a and j - 1 from b.

thus: max(dp[i - 1][1], dp[i - 1][2],..., dp[i - 1][j - 1]) + 1

however, this stil results in a O(N^3) worst case, which is not good enough to pass
further optmization needs to be made 

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
        for (int j=1;j<N+1;j++){
            dp[i][j] = dp[i - 1][j];
            if (a[i] == b[j]){
                dp[i][j] = max(dp[i][j], 1);
                for (int k=1;k<j;k++){
                    if (b[k] < b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
                }
            }
        }
    }

    int res = 0;
    for (int i=1;i<N+1;i++) res = max(res, dp[N][i]);

    cout << res << '\n';

    return 0;
}