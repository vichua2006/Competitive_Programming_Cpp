/*

essentially same thing as cses coin combination II

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

    cin >> N >> M;
    dp[0] = 1;
    for (int i=1;i<N+1;i++){
        int a; cin >> a;
        for (int j=a;j<M+1;j++) dp[j] += dp[j - a];
    }

    cout << dp[M] << '\n';

    return 0;
}