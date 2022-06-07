/*
dp[i][j] = all the ways to cut a ixj marble, store minimum waste
therefore,

    dp[i][j] = min(dp[i][j], dp[i-1][j] + dp[1][j], ... dp[i/2 + (1&i)][j] + dp[i/2][j]
                dp[i][j-1] + dp[i][1], ...)

runtime: O(H*W*(H+W)) ~ O(N^3) should pass
also yey first IOI problem
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 6e2 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M, K;
int dp[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO("snakes");

    cin >> N >> M >> K;
    for (int i=1;i<N+1;i++) for (int j=1;j<M+1;j++) dp[i][j] = i*j;
    for (int i=0;i<K;i++){
        int a,b; cin >> a >> b;
        dp[a][b] = 0;
    }
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            if (i > 1){
                for (int k=i-1;k>=i/2;k--) dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j]);
            }
            if (j > 1){
                for (int k=j-1;k>=j/2;k--) dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k]);
            }
        }
    }
    cout << dp[N][M] << '\n';
    return 0;
}