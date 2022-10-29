/*

this is basically the same problem as counting tiles

even tho k <= 100, but if we only consider one row, then there can be at most 2^10 placements, even including the invalid ones
hence, the state representation is much similar to the counting tiles problem

let dp[i][j][k] denote the set of all the solutions where j kings have been placed in the first i columns, and the last column was placed in the arrangment of k,
where k is a binary number

similar to the other problem we can precompute all the valid ks and arrangements that are valid in combination with k, which, according to the last
time I did this, can SIGNIFICANTLY reduce time (see counting tiles)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 20, maxM = 1 << 11, INF = 1e9, MOD = 1e9 + 7;
int N, M;
ll dp[maxN][maxN * maxN][maxM];
bool val[maxM];
// valid k's
vector<int> vks[maxM];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    // compute the valid placements
    for (int i=0;i<(1<<N);i++){
        int cnt = 0;
        bool flag = 1;
        for (int j=0;j<N;j++){
            if (((i >> j) & 1) == 0){
                if (cnt > 1){
                    flag = 0;
                    break;
                }
                cnt = 0;
            } else cnt += 1;
        }
        if (cnt > 1) flag = 0;
        val[i] = flag;
    }

    // compute all the possible combinations
    for (int i=0;i<(1<<N);i++){
        for (int j=0;j<(1<<N);j++){
            if ((i & j) == 0 && val[i | j]) vks[i].push_back(j);
        }
    }

    // final answer should be dp[N + 1][M][0]
    dp[0][0][0] = 1;
    for (int i=1;i<=N+1;i++){
        for (int j=0;j<M+1;j++){
            for (int k=0;k<(1<<N);k++){
                int kcnt = __builtin_popcount(k);
                if (!val[k] || kcnt > j) continue;
                for (int l : vks[k]){
                    if (__builtin_popcount(l) > j - kcnt) continue;
                    dp[i][j][k] +=  dp[i - 1][j - kcnt][l];
                }
            }
        }
    }

    cout << dp[N + 1][M][0] << '\n';

    return 0;
}