/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int T, N;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char g[maxN][maxN];
bool vis[maxN][maxN];

bool e(int x, int y){
    return 0 <= x && x <= N - 1 && 0 <= y && y <= N - 1 && (g[x][y] != '#');
}

void dfs(int x, int y){
    vis[x][y] = 1;
    for (int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (!e(nx, ny) || vis[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T -- ){
        cin >> N;
        memset(vis, 0, sizeof(vis));
        for (int i=0;i<N;i++) cin >> g[i];

        int a, b, c, d; cin >> a >> b >> c >> d;
        if (g[a][b] != '#') dfs(a, b);
        if (vis[c][d]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}