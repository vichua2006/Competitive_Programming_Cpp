/*

again, basically the same thing as counting tiles but with a little twist

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 15, maxM = 1 << 13, INF = 1e9, MOD = 1e8;
int N, M;
bool corn[maxN][maxN];
bool val[maxM];
ll dp[maxN][maxM];
vector<int> vks[maxM];

bool e(int x, int c){
    // checks if x is a valid way to plant on column c
    for (int i=0;i<N;i++){
        if (((x >> i) & 1) && corn[i + 1][c] == 0) return false;
    }

    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;

    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++) cin >> corn[i][j];
    }

    for (int i=0;i<(1<<N);i++){
        int cnt = 0;
        bool flag = 1;
        for (int j=0;j<N;j++){
            if (((i >> j) & 1) == 0){
                if (cnt > 1) flag = 0;
                cnt = 0;
            } else {
                cnt ++ ;
            }
        }
        if (cnt > 1) flag = 0;
        val[i] = flag;
    }

    for (int i=0;i<(1<<N);i++){
        for (int j=0;j<(1<<N);j++){
            // as long as they don't overlap
            if ((i & j) == 0 && val[j]) vks[i].push_back(j);
        }
    }

    // planting on the 0 col and planting nothing: 1 way
    dp[0][0] = 1;
    for (int i=1;i<M+2;i++){
        for (int j=0;j<(1<<N);j++){
            if (!e(j, i)) continue;
            for (int k : vks[j]){
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    // planting on the M + 1 col and planting nothing
    cout << dp[M + 1][0] << '\n';

    return 0;
}