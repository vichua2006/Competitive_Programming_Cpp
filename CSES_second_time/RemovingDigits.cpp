#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
int N,dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for (int i=1;i<N+1;i++){
        int k=10;
        while (k/10<=i){
            int digit = (i%k)/(k/10);
            // cout << digit << '\n';
            dp[i] = min(dp[i],dp[i-digit]+1);
            k *= 10;
        }
    }
    cout << dp[N] << '\n';
    return 0;
}