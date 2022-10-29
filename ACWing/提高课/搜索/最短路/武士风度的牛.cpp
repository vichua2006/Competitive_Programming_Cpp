/*

basically CCC 2010 J5

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 150 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int dis[maxN][maxN];
char g[maxN][maxN];
bool vis[maxN][maxN];
int dx[4] = {1, 1, -1, -1}, dy[4] = {2, -2, 2, -2};

bool e(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= M && g[x][y] != '*';
}

void bfs(int sx, int sy){
    queue<ar<int, 2>> q;
    vis[sx][sy] = 1;
    q.push({sx, sy});

    while (q.size()){
        auto node = q.front(); q.pop();
        int x = node[0], y = node[1];
        for (int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (e(nx, ny) && (!vis[nx][ny])){
                dis[nx][ny] = dis[x][y] + 1;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
            nx = x + dy[i], ny = y + dx[i];
            if (e(nx, ny) && (!vis[nx][ny])){
                dis[nx][ny] = dis[x][y] + 1;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> M >> N;
    int a, b, c, d;
    for (int i=1;i<N+1;i++){
        cin >> g[i] + 1;
        for (int j=1;j<M+1;j++){
            if (g[i][j] == 'K') a = i, b = j, g[i][j] = '.';
            if (g[i][j] == 'H') c = i, d = j, g[i][j] = '.';
        }
    }

    bfs(a, b);
    cout << dis[c][d] << '\n';

    return 0;
}