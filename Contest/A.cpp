/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1 + 10, INF = 1e9, MOD = 1e9 + 7;
int N = 8, M = 8, ans = 0;
int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};
char g[maxN][maxN];

bool e(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void dfs(int x, int y, int cnt){
    for (int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (!e(nx, ny) || g[nx][ny] != 'B') continue;

        int nnx = x + 2 * dx[i], nny = y + 2 * dy[i];
        if (!e(nnx, nny) || g[nnx][nny] != '.') continue;

        g[nx][ny] = '.';
        dfs(nnx, nny, cnt + 1);
        g[nx][ny] = 'B';
    }

    ans = max(ans, cnt);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    for (int i=0;i<N;i++) for (int j=-0;j<M;j++) cin >> g[i][j];

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (g[i][j] == 'A') dfs(i, j, 0);
        }
    }

    cout << ans << '\n';

    return 0;
}