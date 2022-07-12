/*

a 0-1 bfs problem

we first have to determine whether or not it is possible for the light to reach the target at all
notice that when the light first enters (0,0), in comes in vertically and leaves the cell horizontally
and in (0,1), it enters horizontally and leaves vertically 

generally, for any cell (r,c), if r + c = 0 (mod 2), then light will only enter it from top or bottom, but not from left or right
and vice versa for r + c = 1 (mod 2) 

since the target is under the last cell, the light needs to enter the last cell horizontally
meaning that N + M = 1 (mod 2) must hold true. Otherwise -1

then, we view each cell as a node of a graph. we can either travel in the direction the mirror points to, or flip once and go
in the other direction. We can use the number of flips as weight and perform 0-1 bfs on it

the minimum weight required to get to (N, M) (and with it being \) is the answer


3 6
\\/\/\
\\\\\\
\/\/\\

this case will result in 1 when it should be 0

this is because the light hits the same mirror twice

fuck this

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool e(int x, int y){
    return 0<=x&&x<N&&0<=y&&y<M;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    vector<vector<char>> g(N, vector<char> (M));
    vector<vector<int>> dis(N, vector<int> (M, INF));
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) cin >> g[i][j];

    // N + M must mod 2 to 1
    if ((N + M)%2 != 1){
        cout << -1 << '\n';
        return 0;
    }

    // a detailed explaination of 0-1 bfs: https://cp-algorithms.com/graph/01_bfs.html#algorithm
    // (x, y, c, direction)
    deque<ar<int, 4>> q;
    dis[0][0] = 0;
    q.push_back({0, 0, 0, 0});
    while (q.size()){
        auto node = q.front(); q.pop_front();
        int x = node[0], y = node[1], c = node[2], dir = node[3];
        // dir: 0 up, 1 down, 2 left, 3 right
        if (x == N-1 && y == M-1) break;

        // this following part is excrutiating to write.

        if (g[x][y] == '/'){
            if ((x + y)%2){
                // comes in from left or right
                if (dir == 2){
                    // left
                    if (e(x+1, y) && dis[x+1][y] > c+1) q.push_back({x+1, y, c+1, 0}), dis[x+1][y] = c+1;
                    if (e(x-1, y) && dis[x-1][y] > c) q.push_front({x-1, y, c, 1}), dis[x-1][y] = c;
                } else {
                    // right
                    if (e(x-1, y) && dis[x-1][y] > c+1) q.push_back({x-1, y, c+1, 1}), dis[x-1][y] = c+1;
                    if (e(x+1, y) && dis[x+1][y] > c) q.push_front({x+1, y, c, 0}), dis[x+1][y] = c;
                }
            } else {
                // comes in from up or down
                if (dir == 0){
                    // up
                    if (e(x, y+1) && dis[x][y+1] > c+1) q.push_back({x, y+1, c+1, 2}), dis[x][y+1] = c+1;
                    if (e(x, y-1) && dis[x][y-1] > c) q.push_front({x, y-1, c, 3}), dis[x][y-1] = c;
                } else {
                    // down
                    if (e(x, y-1) && dis[x][y-1] > c+1) q.push_back({x, y-1, c+1, 3}), dis[x][y-1] = c+1;
                    if (e(x, y+1) && dis[x][y+1] > c) q.push_front({x, y+1, c, 2}), dis[x][y+1] = c;
                }
            }
        } else {
            // g[x][y] == '\'
            if ((x + y)%2){
                if (dir == 2){
                    if (e(x+1, y) && dis[x+1][y] > c) q.push_front({x+1, y, c, 0}), dis[x+1][y] = c;
                    if (e(x-1, y) && dis[x-1][y] > c+1) q.push_back({x-1, y, c+1, 1}), dis[x-1][y] = c+1;
                } else {
                    // right
                    if (e(x-1, y) && dis[x-1][y] > c) q.push_front({x-1, y, c, 1}), dis[x-1][y] = c;
                    if (e(x+1, y) && dis[x+1][y] > c+1) q.push_back({x+1, y, c+1, 0}), dis[x+1][y] = c+1;
                }
            } else {
                // comes in from up or down
                if (dir == 0){
                    // up
                    if (e(x, y+1) && dis[x][y+1] > c) q.push_front({x, y+1, c, 2}), dis[x][y+1] = c;
                    if (e(x, y-1) && dis[x][y-1] > c+1) q.push_back({x, y-1, c+1, 3}), dis[x][y-1] = c+1;
                } else {
                    // down
                    if (e(x, y-1) && dis[x][y-1] > c) q.push_front({x, y-1, c, 3}), dis[x][y-1] = c;
                    if (e(x, y+1) && dis[x][y+1] > c+1) q.push_back({x, y+1, c+1, 2}), dis[x][y+1] = c+1;
                }
            }
        }
        
    }
    dis[N-1][M-1] += (g[N-1][M-1] == '/' ? 1:0);
    cout << (dis[N-1][M-1] < INF ? dis[N-1][M-1] : -1) << '\n';
    return 0;
}