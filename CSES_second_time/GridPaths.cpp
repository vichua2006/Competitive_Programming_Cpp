#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,dp[maxN][maxN];
char g[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<N+1;j++){
            cin >> g[i][j];
        }
    }
    dp[1][1] = (g[1][1]!='*');
    for (int i=1;i<N+1;i++){
        for (int j=1;j<N+1;j++){
            if (g[i][j]!='*') dp[i][j] += (dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    cout << dp[N][N] << '\n';
    return 0;
}