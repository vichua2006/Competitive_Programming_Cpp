// 1 dimensional dp?
// 2d, with longest increasing subsequence type logic
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
//dp[i][j] = # of ways to fill up to index i with the ith number in the array being = to j
// designed so that the 0th and the 101st row is empty to avoid conditional statements
ll N,M,arr[maxN],dp[maxN][102];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> arr[i];

    //initialize the first row
    for (int i=1;i<M+1;i++){
        dp[1][i] = (arr[1] == i|| arr[1] == 0);
    }
    //start dp
    for (int i=2;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            // if x[i] != j && x[i] != 0, then there's no way to fill position i with j
            if (arr[i] == 0||arr[i] == j){
                // we don't need to worry of index being at 1 or 100 
                //the number of ways to fill cell i with j is equal the sum of the number of ways cell i-1 can be filled with j-1,j,j+1
                dp[i][j] += (dp[i-1][j+1]+dp[i-1][j]+dp[i-1][j-1])%MOD; 
            }
        }
    }
    //sum the Nth row to get answer
    ll ans = 0;
    for (int i=1;i<M+1;i++) ans = (ans + dp[N][i])%MOD;
    cout << ans << '\n';
    return 0;
}