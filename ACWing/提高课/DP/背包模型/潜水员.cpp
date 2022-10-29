/*

for knapsack problems, the size aspect can hold three different meanings

1. using no more than j units of space (most regular knapsacks)
    the initialization are usually all 0s 
2. using exactly j units of space
    dp[0][0] is set to 0, the rest to INF/-INF depending on whether it's finding the min or max value
3. using at least j units of space
    dp[0][0] is set to 0, and others to INF/-INF, and dp[i][-j] can exists (but only makes sense under the context of finding min)
    which equals to setting -j to 0

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M, K;
int dp[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> K;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i=0;i<K;i++){
        int a, b, c; cin >> a >> b >> c;
        for (int j=N;j>=0;j--){
            for (int k=M;k>=0;k--){
                // another way to understand it is that it accounts for 
                // items with sizes that are greater than (j, k)
                int x = j - a, y = k - b;
                if (x < 0) x = 0;
                if (y < 0) y = 0;
                dp[j][k] = min(dp[j][k], dp[x][y] + c);
            }
        }
    }

    cout << dp[N][M] << '\n';

    return 0;
}