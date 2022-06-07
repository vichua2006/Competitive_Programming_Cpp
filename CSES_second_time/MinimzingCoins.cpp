#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 1e6 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
int N,M,dp[maxN],w[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    memset(dp,0x3f,sizeof(dp));
    for (int i=1;i<N+1;i++) cin >> w[i];
    dp[0] = 0;
    for (int i=1;i<M+1;i++){
        for (int j=1;j<N+1;j++){
            if (i>=w[j]){
                dp[i] = min(dp[i],dp[i-w[j]]+1);
            }
        }
    }
    cout << (dp[M]==0x3f3f3f3f?-1:dp[M]) << '\n';
    return 0;
}
