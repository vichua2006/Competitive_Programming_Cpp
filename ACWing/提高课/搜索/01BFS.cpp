/*

each intersection in the grid could be considered as a node, and each wire an edge

first realize that there are nodes that can never be reached. Specifically, nodes with coordinates (x, y) such that 
x + y = 0 （mod 2)

suppose we are at node (a, b). The directions we can moving are (a + 1, b + 1), (a - 1, b + 1), (a + 1, b - 1), (a - 1, b - 1), 
which changes the sum of the coordinates by an even amount, which means that its parity will remain the same.

since we start on (0, 0) (or (1, 1), doesn't matter), we will only be able to reach "even" nodes 

because of this property, we will be able to avoid the same wires changing direction during the search
consider the wire between (a, b) and (a + 1, b + 1), it cannot possibly connect (a + 1, b) and (a, b + 1) because they are "odd" nodes in the first place

hence, each is neither already in place or has to be turned, rather, a weight of 0 or 1, which calls for 0-1 bfs

interestingly, to know if a searcing algorithm is correct or not, see if it can be converted to dijkstra, because if it can, than it is correct
because dijkstra is correct.

and since each node may be enqueued multiple times, we follow dijkstra where the node marked as visited only after it comes out of the queue.

there a few new techniques regarding converting between the coordinates of the intersection of a grid to the cell of a grid that is worth noting

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int T, N, M;
char g[maxN][maxN];
int dis[maxN][maxN];
bool vis[maxN][maxN];

bool e(int x, int y){
    return 1 <= x && x <= N + 1 && 1 <= y && y <= M + 1;
}

int bfs(){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    // (a - 1, b - 1), (a - 1, b + 1), (a + 1, b + 1), (a + 1, b - 1)
    int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
    // adjusts the point to the corresponding cell
    // (a - 1, b - 1), (a - 1, b), (a, b), (a, b - 1)
    int wx[] = {-1, -1, 0, 0}, wy[] = {-1, 0, 0, -1};
    // the correct wire in for each direction
    string cw = "\\/\\/";

    deque<ar<int, 2>> q;
    q.push_back({1, 1});
    dis[1][1] = 0;

    while (q.size()){
        auto node = q.front(); q.pop_front();
        int x = node[0], y = node[1];
        if (vis[x][y]) continue;
        vis[x][y] = 1; 

        for (int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (!e(nx, ny)) continue;
            int w = int(g[x + wx[i]][y + wy[i]] != cw[i]);
            if (dis[x][y] + w < dis[nx][ny]){
                dis[nx][ny] = dis[x][y] + w;
                if (w) q.push_back({nx, ny});
                else q.push_front({nx, ny});

            }
        }
    }

    // since there is one more intersection than there are cells, the answer is at (N + 1, M + 1)

    return dis[N + 1][M + 1];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T -- ){
        cin >> N >> M;
        for (int i=1;i<N+1;i++) cin >> g[i] + 1;

        if ((N + M) & 1) cout << "NO SOLUTION\n";
        else cout << bfs() << '\n';
    }

    return 0;
}