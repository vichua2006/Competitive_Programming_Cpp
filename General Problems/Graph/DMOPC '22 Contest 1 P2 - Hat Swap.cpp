/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int c[maxN];
int node[2][maxN], dis[2][maxN];
int cdis[2][maxN][2];
bool vis[maxN];
vector<int> g[maxN];

void bfs(int s, int t){
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(s); 
    vis[s] = 1;
    dis[t][s] = 0;
    while (q.size()){
        int v = q.front(); q.pop();
        for (int a: g[v]){
            if (!vis[a]){
                vis[a] = 1;
                dis[t][a] = dis[t][v] + 1;
                q.push(a);
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> c[i];
    for (int i=0;i<M;i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }

    memset(cdis, 0x3f, sizeof(cdis));
    memset(dis, 0x3f, sizeof(dis));
    memset(node, -1, sizeof(node));
    // the hats that shirogane can get
    bfs(1, 0);
    // the hats that kaguya can get
    bfs(N, 1);

    // iterate the dis for each node, and compute the smallest and second smallest distance to each color
    for (int i=0;i<2;i++){
        for (int j=1;j<N+1;j++){
            int &d1 = cdis[i][c[j]][0], &d2 = cdis[i][c[j]][1];
            if (dis[i][j] <= d1) d2 = d1, d1 = dis[i][j], node[i][c[j]] = j;
            else if (dis[i][j] < d2) d2 = dis[i][j];
        }
    }


    int res = INF;
    for (int i=1;i<N+1;i++){
        if (node[0][i] == -1 || node[1][i] == -1) continue;
        if (node[0][i] == node[1][i]){
            res = min(res,
                min(cdis[0][i][0] + cdis[1][i][1], cdis[0][i][1] + cdis[1][i][0])
            );
        } else {
            res = min(res, cdis[0][i][0] + cdis[1][i][0]);
        }
    }

    cout << (res > INF / 2 ? -1 : res) << '\n';



    return 0;
}