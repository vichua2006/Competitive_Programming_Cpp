/*

the next optimization is rooted in the fact that both paths will end on the final cell
(it cannot work if, say, the problem asks Q queries on the max sum achieved if A walks to (i, j) and B to (k, l))

since the answer only requires information on positions where they've walked the same number of steps 
(they both end on the same cell, and thus same number of steps), we can suppose that the two people are 
moving together

thus, (i1, j1) and (i2, j2) will always satisfy i1 + j1 == i2 + j2

since we only need such states, we can let k = i1 + j1
thus, f[i1][j1][i2][j2] = f[i1][k - i1][i2][k - i2]
since (j1, j2) are dependent on (k, i1, i2), we simply replace them
thus, f[k][i1][i2] represents the same thing as f[i1][k - i1][i2][k - i2] = f[i1][j1][i2][j2]
(it can be shown that there is a one-to-one correspondence...)

and the 4 states are : dp[k - 1][i][j], dp[k - 1][i][j - 1], dp[k - 1][i - 1][j], dp[k - 1][i - 1][j - 1]

computed linearly is fine

(or, think about this in terms of "last step". to get to dp[i][j][k][l], the distinct last steps must have been those 4)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 20 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN][maxN];
int dp[maxN][maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    int a, b, c;
    while ( cin >> a >> b >> c, a || b || c) arr[a][b] = c;

    memset(dp, -0x3f, sizeof(dp));
    dp[2][1][1] = 0;
    for (int k=2;k<=2*N;k++){
        for (int i=1;i<N+1;i++){
            for (int j=1;j<N+1;j++){
                dp[k][i][j] = max(
                    dp[k][i][j],
                    max(
                        max(dp[k - 1][i][j], dp[k - 1][i - 1][j - 1]),
                        max(dp[k - 1][i - 1][j], dp[k - 1][i][j - 1])
                    )
                );

                if (i == j) dp[k][i][j] += arr[i][k - i];
                else dp[k][i][j] += arr[i][k - i] + arr[j][k - j];
            }
        }
    }

    cout << dp[2 * N][N][N] << '\n';
    return 0;
}