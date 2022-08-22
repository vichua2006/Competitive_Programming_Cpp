/*

classic interval dp
dp[l][r] represents all the ways to combine interval [l,r] into one piece
value stored is min

dp[l][r] = min(dp[l][l+k]+dp[l+k+1][r]) + sum(l~r), 0<=k<=r-l
since each rock has to be combined from two smaller rocks, 
the only way to combine the interval [l,r] together is to first combine the 
interval into two, then into one. we iterate through all the options and pick
the smallest one.

if l == r, dp[l][r] = 0
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 3e2 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,dp[maxN][maxN],pre[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
    
    cin >> N;
    for (int i=1;i<N+1;i++){
        int a; cin >> a;
        pre[i] = a+pre[i-1];
    }
    memset(dp,0x3f,sizeof(dp));
    // j is l, i is r
    for (int i=1;i<N+1;i++){
        for (int j=i;j>0;j--){
            if (i == j) dp[j][i] = 0;
            else{
                for (int k=0;k<=i-j;k++){
                    dp[j][i] = min(dp[j][i],dp[j][j+k]+dp[j+k+1][i] + pre[i]-pre[j-1]);
                }
            }
        }
    }
    cout << dp[1][N] << '\n';
    return 0;
}