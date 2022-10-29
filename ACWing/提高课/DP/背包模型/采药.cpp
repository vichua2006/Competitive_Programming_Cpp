/*

0-1 knapsack, really nothing to say here

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> M >> N;
    for (int i=1;i<N+1;i++){
        int v, w; cin >> v >> w;
        for (int j=M;j>=v;j--) dp[j] = max(dp[j], dp[j - v] + w);
    }

    cout << dp[M] << '\n';

    return 0;
}