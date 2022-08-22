/*

basically memorized recursion = dp, but more flexable in terms of order, but takes longer
literally the same thing as dp on tp, but because of the characteristic of the graph, it's a DAG, so we don't need to tp

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e2 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
int g[maxN][maxN], memo[maxN][maxN];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool e(int x, int y){
    return 0 <= x && 0 <= y && x < N && y < M;
}

void dfs(int x, int y){
    if (memo[x][y]) return;

    int msf = 0;
    for (int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (e(nx, ny) && g[nx][ny] < g[x][y]){
            dfs(nx, ny);
            msf = max(msf, memo[nx][ny]);
        }
    }

    memo[x][y] = msf + 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) cin >> g[i][j];
    int ans = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (!memo[i][j]) dfs(i, j);
            ans = max(ans, memo[i][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}