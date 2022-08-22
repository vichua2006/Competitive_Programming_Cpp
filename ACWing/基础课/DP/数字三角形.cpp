/*

lit. linear dp
dp[i][j] will represent the set of all possible paths from the first number 
in teh first row to the jth numebr in the ith row. the value stored will be the max

if j==1||j==i, dp[i][j] = dp[(j==1?dp[i-1][j]:dp[i-1][j-1])] + v[i][j]

if the jth numebr is either first of last, then we must of arrived there from
the first or last numebr in the previous row, respectively.

else dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + v[i][j];

else, it must have came from either the jth number in the previous row,
or the j-1th numebr from the previous row

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e2 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,dp[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) for (int j=1;j<i+1;j++) cin >> dp[i][j];
    for (int i=2;i<N+1;i++){
        for (int j=1;j<i+1;j++){
            if (j==1||j==i) dp[i][j] += (j==1?dp[i-1][j]:dp[i-1][j-1]);
            else dp[i][j] += max(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    int ans = -INF;
    for (int i=1;i<N+1;i++) ans = max(ans,dp[N][i]);
    cout << ans << '\n';
    return 0;
}
