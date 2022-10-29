/*

classic floodfill with dfs counting components. This is like the third or fourth time writing this.
so, this should actually be solved with bfs, because the largest possible pond is of size 1e6, which 
would definitly cause stack overflow for recursive dfs

luckily, it didn't

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
char arr[maxN];
bool g[maxN][maxN], vis[maxN][maxN];
int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1}, dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

bool e(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= M && (!vis[x][y]) && g[x][y];
}

void dfs(int x, int y){
    vis[x][y] = 1;
    for (int i=0;i<8;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (e(nx, ny)) dfs(nx, ny);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        cin >> arr + 1;
        for (int j=1;j<M+1;j++){
            if (arr[j] == 'W') g[i][j] = 1;
        }
    }

    int cnt = 0;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            if (!vis[i][j] && g[i][j]) dfs(i, j), cnt += 1;
        }
    }

    cout << cnt << '\n';

    return 0;
}