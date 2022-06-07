/*

dp[i][j] = set of all ways to cut rect of size i by j into squares

dp[i][j] = 
(cutting the i side)
min( dp[1][j]+dp[i-1][j], dp[2][j]+dp[i-2][j]...dp[i/2][j]+dp[i-i/2][j])
(cutting the j side)
min( dp[i][1]+dp[i][j-1]....dp[i][j/2]+dp[i][j-j/2])

complexity around O(N^3) ?
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 501,INF = 1e9;

int a,b,dp[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> a >> b;
    // memset(dp,0x3f,sizeof(dp));
    for (int i=1;i<a+1;i++){
        for (int j=1;j<b+1;j++){
            dp[i][j] = INF;
            if (i==j) dp[i][j] = 0;
            else{
                for (int x=1;x<=i/2+1;x++){
                    dp[i][j] = min(dp[i][j],dp[i-x][j]+dp[x][j]+1);
                }
                for (int x=1;x<=j/2+1;x++){
                    dp[i][j] = min(dp[i][j],dp[i][j-x]+dp[i][x]+1);
                }
            }
        }
    }
    cout << dp[a][b] << '\n';
    return 0;
}