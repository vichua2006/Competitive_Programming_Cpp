/*

knight's tour

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 10, INF = 1e9, MOD = 1e9 + 7;
int T, N, M, res;
int dx[4] = {1, -1, 1, -1}, dy[4] = {2, 2, -2, -2};
vector<ar<int, 2>> g[maxN][maxN];
bool vis[maxN][maxN];

bool e(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

bool comp(ar<int, 2> &a, ar<int, 2> &b){
    return g[a[0]][a[1]].size() > g[b[0]][b[1]].size();
}

void dfs(int x, int y, int cnt){
    vis[x][y] = 1;
    if (cnt == N * M) res += 1;
    else {
        for (auto a: g[x][y]){
            if (!vis[a[0]][a[1]]) dfs(a[0], a[1], cnt + 1);
        }
    }
    vis[x][y] = 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T -- ){
        cin >> N >> M;
        int a, b; cin >> a >> b;
        a ++ , b ++ ;

        for (int i=1;i<N+1;i++){
            for (int j=1;j<M+1;j++){
                g[i][j].clear();
                for (int k=0;k<4;k++){
                    if (e(i + dx[k], j + dy[k])) g[i][j].push_back({i + dx[k], j + dy[k]});
                    if (e(i + dy[k], j + dx[k])) g[i][j].push_back({i + dy[k], j + dx[k]});
                }
            }
        }

        for (int i=1;i<N+1;i++){
            for (int j=1;j<M+1;j++){
                sort(g[i][j].begin(), g[i][j].end(), comp);
            }
        }

        res = 0;
        dfs(a, b, 1);

        cout << res << '\n';
    }

    return 0;
}