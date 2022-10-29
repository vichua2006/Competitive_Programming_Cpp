/*

0-1 knapsack, but just computing number of possible answers instead of min/max values 

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 10, maxM = 1e5 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int dp[maxM];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    // dp[i][0] = 1 for all i
    dp[0] = 1;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        for (int j=M;j>=a;j--) dp[j] += dp[j - a];
    }

    cout << dp[M] << '\n';

    return 0;
}