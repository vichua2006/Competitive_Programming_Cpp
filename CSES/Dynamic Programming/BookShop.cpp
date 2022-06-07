// a slight variation of the coin problem
// seems like I underestinmated the problem, it's actually 2d dp and resembles (is?) knapsack

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxX = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
// dp[i][j] = max page you can get with j dollars and the first i books
int N,X,dp[1001][maxX],h[1001],s[1001];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> X;
    // sync up the indexing
    for (int i=1;i<N+1;i++) cin >> h[i];
    for (int i=1;i<N+1;i++) cin >> s[i];

    for (int i=1;i<N+1;i++){
        for (int j=1;j<X+1;j++){
            // each dp[i][j] equals max( max page without the ith book, max page with the ith book)
            // hence:
            if (j >= h[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-h[i]] + s[i]);
            else dp[i][j] = dp[i-1][j];
            // since the first row and first col are 0's, i-1 shouldn't cause indexing issues
        }
    }
    cout << dp[N][X] << '\n';
    return 0;
}