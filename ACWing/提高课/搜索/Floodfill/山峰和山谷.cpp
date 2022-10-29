/*

a slight variation of floodfill, we simply need to add a few boolean variables in the solving function

if an area is both, then it is simply a plateau (neither), and for the extreme case of the entire array having the same
numbers, both flags will be at false, which indicates that it is indeed the corner case

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int g[maxN][maxN];
bool vis[maxN][maxN];
int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1}, dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

bool e(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

ar<bool, 2> dfs(int sx, int sy){
    vector<ar<int, 2>> stk;
    bool is_p = 0, is_v = 0;
    vis[sx][sy] = 1;
    stk.push_back({sx, sy});

    while (stk.size()){
        auto node = stk.back(); stk.pop_back();
        int x = node[0], y = node[1];
        for (int i=0;i<8;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (!e(nx, ny)) continue;
            int val = g[nx][ny];
            // leave checking for visited outside of e function, 
            // as it needs to check if val if greater or less even if the node was already visited
            if (val == g[x][y] && (!vis[nx][ny])){
                vis[nx][ny] = 1;
                stk.push_back({nx, ny});
            } else {
                if (val > g[x][y]) is_v = 1;
                if (val < g[x][y]) is_p = 1;
            }
        }
    }

    return {is_p, is_v};
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) for (int j=1;j<N+1;j++) cin >> g[i][j];
    int peak = 0, valley = 0;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<N+1;j++){
            if (!vis[i][j]){
                auto res = dfs(i, j);
                if (res[0] && res[1]) continue;
                if (res[0]) peak ++ ;
                if (res[1]) valley ++ ;
                if (!(res[0] || res[1])) peak ++ , valley ++ ;
            }
        }
    }

    cout << peak << ' ' << valley << '\n';

    return 0;
}