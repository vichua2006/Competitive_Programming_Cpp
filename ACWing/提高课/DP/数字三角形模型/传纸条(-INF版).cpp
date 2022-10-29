/*

the code is a bit ugly and unorganized, but the basic solution is to set all dp[i][j][i][j] to -INF.
it prevents any possiblities of two paths that goes through the same cell
(when computing future states, it will not be affected by such paths)

the optimization is the same as the previous problem



*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 110 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
int arr[maxN][maxN];
int dp[maxN][maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool e(int x, int y){
    return 1 <= x && x <= M && 1 <= y && y <= M;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) for (int j=1;j<M+1;j++) cin >> arr[i][j];

    memset(dp, -0x3f, sizeof(dp));
    dp[2][1][1] = 0;
    for (int k=2;k<=N+M;k++){
        for (int i=1;i<N+1;i++){
            for (int j=1;j<N+1;j++){
                // the first and last case is a bit of a exception, so it get messy trying to sort those in order
                if (k == 2 && i == 1 && j == 1){
                    dp[k][i][j] += arr[1][1];
                    continue;
                }
                else if (i == j || !e(k - i, k - j)) continue;
                dp[k][i][j] = max(
                    dp[k][i][j],
                    max(
                        max(dp[k - 1][i][j], dp[k - 1][i - 1][j - 1]),
                        max(dp[k - 1][i - 1][j], dp[k - 1][i][j - 1])
                    )
                );

                dp[k][i][j] += arr[i][k - i] + arr[j][k - j];
            }
        }
    }   

    dp[N + M][N][N] = max(
        max(dp[N + M - 1][N][N], dp[N + M - 1][N - 1][N - 1]),
        max(dp[N + M - 1][N - 1][N], dp[N + M - 1][N][N - 1])
    );

    dp[N + M][N][N] += arr[N][M];

    cout << dp[N + M][N][N] << '\n';
    return 0;
}