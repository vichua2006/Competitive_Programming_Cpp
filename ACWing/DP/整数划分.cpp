/*

similair to ccc 15 J5

there's actually two ways
1. unobounded knapsack, weights are 1,2,3...N, count how may ways to achieve N: dp[i][j] = dp[i-1][j] + dp[i][j-i]

2. let dp[i][j] the set of all ways to obtain a sum of i with exactly j numbers. stored value is size

this can be splite into two subsets.
for sum of i using j numbers:
1. the minimum value in the j numbers is 1
2. the minimum value is greater than 1

for each 1., it corrisponds to a situation where a sum of i-1 is achieved with j-1 numbers: dp[i-1][j-1]
for each 2., we can subtract 1 from all j numbers. this corrisponds to a situation where a sum of i-j is achieved
with j numbers. (for every such situation, we can just add 1 to every number to obtain 2.): dp[i-j][j]

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,dp[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    //init: exactly 1 way to achieve sum of i with i weights
    // --> same thing achieved with dp[0][0] = 1
    dp[0][0] = 1;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<=i;j++){
            dp[i][j] = (dp[i-1][j-1]+dp[i-j][j])%MOD;
        }
    }
    int ans = 0;
    // it wants the total ways to split N, so we sum it up
    for (int i=1;i<N+1;i++) ans = (ans+dp[N][i])%MOD;
    cout << ans << '\n';
    return 0;
}