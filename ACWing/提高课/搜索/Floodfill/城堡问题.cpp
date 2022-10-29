/*

still floodfill, but we just have to check whether or not there is a wall in the direction we want to head in 

this one has N, M <= 50, so we can use recursive dfs. however, since this one requires us to output the largest room (size) as well
it is faster to use iterative dfs

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 50 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int g[maxN][maxN];
bool vis[maxN][maxN];
// this actually had to be carefully made to ensure that the directions matched up with the problem's wall directions
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

bool e(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= M && (!vis[x][y]);
}

int dfs(int sx, int sy){
    vector<ar<int, 2>> stk;
    vis[sx][sy] = 1;
    stk.push_back({sx, sy});

    int cnt = 1;
    while (stk.size()){
        auto node = stk.back(); stk.pop_back();
        int x = node[0], y = node[1];

        for (int i=0;i<4;i++){
            // check the bits of g[i][j] in binary form
            // if there is a wall in the left/up/right/down direction
            if ((g[x][y] >> i) & 1) continue;
            int nx = x + dx[i], ny = y + dy[i];
            if (e(nx, ny)){
                cnt += 1;
                vis[nx][ny] = 1;
                stk.push_back({nx, ny});
            }
        }
    }

    return cnt;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) for (int j=1;j<M+1;j++) cin >> g[i][j];
    int cnt = 0, msf = 0;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            if (!vis[i][j]){
                msf = max(msf, dfs(i, j));
                cnt += 1;
            }
        }
    }

    cout << cnt << '\n' << msf << '\n';

    return 0;
}