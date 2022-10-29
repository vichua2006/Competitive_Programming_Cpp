/*

still 0-1 knapsack with a slight change
let dp[i][j] denote whether or not we can fill j amount of space with the first i objects

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
bool dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> M >> N;
    // init: fill 0 space with 0 objects
    dp[0] = 1;
    for (int i=1;i<N+1;i++){
        int v; cin >> v;
        for (int j=M;j>=v;j--) dp[j] = dp[j] || dp[j - v];
    }   

    int res = 0;
    for (int i=1;i<M+1;i++){
        if (dp[i]) res = i;
    }

    cout << M - res << '\n';

    return 0;
}