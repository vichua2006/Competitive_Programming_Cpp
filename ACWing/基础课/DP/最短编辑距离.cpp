/*

found better way to initialize:
instead of initializing col one and row one, do col 0 and row 0
turn first 0 letters of a into first i letter of b - takes i steps, vice versa

then the row 1 and col 1 can be computed with the usual equation

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN][maxN];
char a[maxN],b[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> a+1 >> M >> b+1;
    // turn first 0 letters of a to first i letters of b
    for (int i=0;i<M+1;i++) dp[0][i] = i;
    // turn first 0 letters of b to first i letters of a
    for (int i=0;i<N+1;i++) dp[i][0] = i;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            dp[i][j] = min(dp[i-1][j-1]+(a[i]!=b[j]),min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
    }
    cout << dp[N][M] << '\n';
    return 0;
}