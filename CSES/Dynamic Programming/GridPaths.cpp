// classic 2d, f[i][j] = f[i-1][j] + f[i][j-1]
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e3 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,dp[maxN][maxN];
char grid[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<N+1;j++){
            cin >> grid[i][j];
        }
    }
    int a = 1,b = 1;
    // initialization
    for (int i=1;i<N+1;i++){
        if (grid[1][i] == '*') a = 0;
        if (grid[i][1] == '*') b = 0;
        dp[1][i] = a;
        dp[i][1] = b;
    }
    for (int i=2;i<N+1;i++){
        for (int j=2;j<N+1;j++){
            if (grid[i][j] != '*'){
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[N][N] << '\n';
    return 0;
}