/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    dp[0] = 1;
    for (int i=1;i<N+1;i++) for (int j=1;j<=min(i,6);j++) dp[i] = (dp[i]+dp[i-j])%MOD;
    cout << dp[N] << '\n';
    return 0;
}