/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN][maxN];
string a,b;
char s1[maxN],s2[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> a >> b;
    N = a.size(),M = b.size();
    for (int i=0;i<N;i++) s1[i+1] = a[i];
    for (int i=0;i<M;i++) s2[i+1] = b[i];

    for (int i=0;i<N+1;i++) dp[i][0] = i;
    for (int i=0;i<M+1;i++) dp[0][i] = i;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            dp[i][j] = min(dp[i-1][j-1]+(s1[i]!=s2[j]),min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
    }
    cout << dp[N][M] << '\n';
    return 0;
}