/*

pascal's theorem: C(k, n) = C(k, n - 1) + C(k - 1, n - 1)
which makes this a simple dp problem

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M = maxN;
// dp[i][j] denotes C(j, i) mod 1e9 + 7
ll dp[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    for (int i=0;i<M;i++){
        for (int j=0;j<=i;j++){
            if (!j) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
            }
        }
    }

    cin >> N;
    while (N -- ){
        int a, b; cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
    return 0;
}