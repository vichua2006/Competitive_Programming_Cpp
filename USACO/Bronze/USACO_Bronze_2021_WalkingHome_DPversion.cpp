/*

dp version

dp[x][y][k][d] = set of all ways to reach cell (x,y) with k turns while heading in direction d
stored value is count

we get can to (x,y) from either (x-1,y) (up) or (x,y-1) (left)

if we go (x-1,y)->(x,y), then we arrive at (x,y) with direction down:
from (x-1,y) with direction 0 or (x-1,y) with direction 1, in which case you need to turn once
dp[x][y][k][0] = dp[x-1][y][k][0] + dp[x-1][y][k-1][1]

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e1 + 1,maxM = 0,maxK = 4,INF = 1e9, MOD = 1e9 + 7;
int T,N,K,dp[maxN][maxN][maxK][2];
char g[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO();

    cin >> T;
    while(T--){
        cin >> N >> K;
        memset(dp,0,sizeof(dp));
        for (int i=1;i<N+1;i++) cin >> g[i]+1;
        //initialization
        for (int i=1;(i<N+1)&&g[1][i]!='H';i++) dp[1][i][0][1] = 1;
        for (int i=1;(i<N+1)&&g[i][1]!='H';i++) dp[i][1][0][0] = 1;
        for (int x=2;x<N+1;x++){
            for (int y=2;y<N+1;y++){
                if (g[x][y] == 'H') continue;
                for (int k=1;k<=K;k++){
                    dp[x][y][k][0] = dp[x-1][y][k][0] + dp[x-1][y][k-1][1];
                    dp[x][y][k][1] = dp[x][y-1][k][1] + dp[x][y-1][k-1][0];
                }
            }
        }
        int cnt = 0;
        for (int i=1;i<=K;i++){
            cnt += dp[N][N][i][0]+dp[N][N][i][1];
        }
        cout << cnt << '\n';
    }
    return 0;
}