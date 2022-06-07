/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,arr[maxN],dp[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> arr[i];
    for (int i=1;i<N+1;i++){
        for (int j=i;j>=1;j--){
            if (i==j) dp[i][j] = arr[i];
            else{
                dp[j][i] = max(
                arr[j]+min(dp[j+1][i-1],dp[j+2][i]),
                arr[i]+min(dp[j+1][i-1],dp[j][i-2])
                );
            }
        }
    }
    cout << dp[1][N] << '\n';
    return 0;
}