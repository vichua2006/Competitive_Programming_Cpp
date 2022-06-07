// same with normal knapsack -. dp[i][j] = max(dp[i-1][j-k*v[i]] + K*w[i]) k = 0,1,2,3,..si ( or until it doesn't fit anymore)
// with n,m,s<=100, even O(N^3) will pass, so this doesn't require mathematical optimization like UKP with large N
// (there probably going to be version where N<=1000 or smt)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 1,INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN][maxN],v[maxN],w[maxN],s[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> v[i] >> w[i] >> s[i];
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            // oh and it's also practical to move the conditions into the for loop
            for (int k=0;k<=s[i]&&j-k*v[i]>=0;k++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-k*v[i]] + k*w[i]);
            }
        }
    }
    cout << dp[N][M] << '\n';
    return 0;
}