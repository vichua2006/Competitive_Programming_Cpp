/*

dp[i][j][k] = set of all the ways bessie could have have played
up to and including ith game with j changes and on the kth state

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxK = 21,INF = 1e9, MOD = 1e9 + 7;
int N,K,dp[maxN][maxK][3],s[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("hps");

    cin >> N >> K;
    for (int i=1;i<N+1;i++){
        char a; cin >> a;
        if (a == 'H') s[i] = 0;
        if (a == 'P') s[i] = 1;
        if (a == 'S') s[i] = 2;
    }
    for (int i=1;i<N+1;i++){
        for (int j=0;j<=K;j++){
            for (int k=0;k<3;k++){
                int ok1 = (k+1)%3,ok2 = (k+2)%3;
                dp[i][j][k] = dp[i-1][j][k] + (s[i]==ok1);
                if (j>0){
                    dp[i][j][k] = max(dp[i][j][k],
                    max(dp[i-1][j-1][ok1],dp[i-1][j-1][ok2]) + (s[i]==ok1));
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=K;i++){
        for (int j=0;j<3;j++) ans = max(ans,dp[N][i][j]);
    }
    cout << ans << '\n';
    return 0;
}