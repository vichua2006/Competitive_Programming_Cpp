/*

0-1 knapsack with two types of volumes

the state representation is dp[i][j][k], denoting the max number of pokemons 
when considering the first i of them, and using no more than j point of health and 
no more than k balls

for each pokemon, we can either choose to capture it or leave it
thus, dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - h[i]][k - b[i]])

since they both only used dp[i - 1], this can be optimized into 2-d

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M, K;
int dp[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    // ball; hp; number of pokemons
    cin >> K >> M >> N;
    for (int i=0;i<N;i++){
        int bl, hl; cin >> bl >> hl;
        for (int j=M-1;j>=hl;j--){
            for (int k=K;k>=bl;k--) dp[j][k] = max(dp[j][k], dp[j - hl][k - bl] + 1);
        }
    }

    // the since the state representation here is "using no more than i balls and j points of health," dp[N][M - 1] is the 
    // optimal solution, and we simply have to find the smallest j such that dp[N][j] still equals dp[N][M - 1];
    int res = dp[M - 1][K], msf = 0;
    for (int i=M - 1;i>=0;i--){
        if (dp[i][K] == res) msf = i;
    }

    cout << res << ' ' << M - msf << '\n';

    return 0;
}