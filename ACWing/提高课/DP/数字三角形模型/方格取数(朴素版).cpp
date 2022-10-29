/*

and the third question directly throws me into confusion for more than a day.
this thing doesn't hold back

and for one thing, 
dp[i][j][k][l] = max(
    dp[i][j][k][l] + arr[i][j], 
    max(
        max(
            dp[i - 1][j][k][l], 
            dp[i][j - 1][k][l]
            ) + arr[i][j], 
        max(
            dp[i][j][k - 1][l],
            dp[i][j][k][l - 1]
            ) + arr[k][l]
        )
    );
if (i == k && j == l && i != 1 && j != 1) dp[i][j][k][l] -= arr[i][j];

this actually over counts, however, this:

dp[i][j][k][l] = max(
    dp[i][j][k][l], 
    max(
        max(
            dp[i - 1][j][k - 1][l], 
            dp[i][j - 1][k - 1][l]
            ), 
        max(
            dp[i - 1][j][k][l - 1],
            dp[i][j - 1][k][l - 1]
            )
        )
);
if (i == k && j == l) dp[i][j][k][l] += arr[i][j];
else dp[i][j][k][l] += arr[i][j] + arr[k][l];

is correct.

the first is modeled with the thought that the two move one at a time, while the second , both move at the same time
they may seem different, but are essentially the same thing; (i, j) must have came from either (i - 1, j) or (i, j - 1)

and while there might be a way to condition the first method so that it works, the second one is simply easier to think about and manage

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 20,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN][maxN];
int dp[maxN][maxN][maxN][maxN];

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
    while (cin >> a >> b >> c, a || b || c) arr[a][b] = c;
    memset(dp, -0x3f, sizeof(dp));
    dp[1][1][1][1] = 0;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<N+1;j++){
            for (int k=1;k<N+1;k++){
                for (int l=1;l<N+1;l++){

                    dp[i][j][k][l] = max(
                        dp[i][j][k][l], 
                        max(
                            max(
                                dp[i - 1][j][k - 1][l], 
                                dp[i][j - 1][k - 1][l]
                                ), 
                            max(
                                dp[i - 1][j][k][l - 1],
                                dp[i][j - 1][k][l - 1]
                                )
                            )
                    );
                    if (i == k && j == l) dp[i][j][k][l] += arr[i][j];
                    else dp[i][j][k][l] += arr[i][j] + arr[k][l];
                }
            }
        }
    }

    cout << dp[N][N][N][N] << '\n';
    return 0;
}