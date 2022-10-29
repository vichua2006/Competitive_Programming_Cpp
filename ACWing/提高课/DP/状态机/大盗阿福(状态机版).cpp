/*

the big idea of the name is just to split ambiguous states into smaller but more specific (sub)states

for example, say we are given the restriction of only being allowed to use the data from the previous row [i - 1] to compute dp[i]
because we don't know whether the i - 1 store was picked or not (ambiguity), we cannot compute the next state

however, if we split dp[i] into dp[i][0] and dp[i][1], where 0 denotes that we did not pick store i and 1 indicating otherwise,
we will have enough information to compute future states even if we can only use the previous layer

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int T, N;
int dp[maxN][2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T -- ){
        cin >> N;
        memset(dp, 0, sizeof(dp));

        for (int i=1;i<N+1;i++){
            int a; cin >> a;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + a;
        }
        
        cout << max(dp[N][0], dp[N][1]) << '\n';
    }


    return 0;
}