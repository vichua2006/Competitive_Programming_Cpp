/*

there are two ways to deal with circular formations,
either iterate all possible cyclic rearrangements (O(N)), or
duplicate the array and append it to the end, creating an array of length 2N

this is a twist on a classic range dp problem, and orginally, dp[i][j] will denote the min/max value required to combine [i, j]
however, applying the first optimization would result in a O(N^4) complexity, which would TLE

thus, we apply the second optimization, and the answer is min/max(dp[1][N], dp[2][N + 1], ... , dp[N][2N - 1])

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 4e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int pre[maxN];
int mx[maxN][maxN], mn[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;

    // compute prefix sum, needed for dp
    for (int i=1;i<N+1;i++) cin >> pre[i];
    for (int i=N+1;i<2*N+1;i++) pre[i] = pre[i - N];
    for (int i=1;i<2*N+1;i++) pre[i] += pre[i - 1];

    memset(mn, 0x3f, sizeof(mn));

    for (int i=1;i<2*N+1;i++){
        // goddamn dp ording, confuses me every single time I write a range dp problem
        for (int j=i;j;j--){
            if (i == j) mn[j][i] = 0;
            int sum = pre[i] - pre[j - 1];
            for (int k=j;k<i;k++){
                mx[j][i] = max(mx[j][i], mx[j][k] + mx[k + 1][i] + sum);
                mn[j][i] = min(mn[j][i], mn[j][k] + mn[k + 1][i] + sum);
            }
        }
    }

    int res1 = 0, res2 = INF;
    for (int i=1;i<N+1;i++){
        res1 = max(res1, mx[i][i + N - 1]);
        res2 = min(res2, mn[i][i + N - 1]);
    }

    cout << res2 << '\n' << res1 << '\n';

    return 0;
}