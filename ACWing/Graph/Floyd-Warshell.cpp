/*

this is actually dp

dp[i][j][k] denotes the shortest path from j to k whilst passing through only the first i nodes

we iterate over i, and each time, we choose whether or not we use i as the intermediate node,
and like knapsack, keep the best solution

and on this thought, spfa is actually not very different from tp sorting a graph and then 
dp ing on it, aside from the fact that dp cannot handle cycles, and spfa can (dp is probably faster, on a second thought)

*/


#include<iostream>
#include<cstring>
using namespace std;


const int maxN = 2e2 + 1;

int N, M, K;
int g[maxN][maxN];

int main(){
    cin >> N >> M >> K;
    memset(g, 0x3f, sizeof(g));
    for (int i=0;i<N+1;i++) g[i][i] = 0;
    for (int i=0;i<M;i++){
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    
    for (int i=1;i<N+1;i++){
        for (int j=1;j<N+1;j++){
            for (int k=1;k<N+1;k++){
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }
    
    for (int i=0;i<K;i++){
        int a, b; cin >> a >> b;
        int res = g[a][b]; 
        if (res > 0x3f3f3f3f / 2) cout << "impossible" << '\n';
        else cout << res << '\n';
    }
    
    return 0;
}