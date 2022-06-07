// appearently called "multi-source BFS"
// bfs search on all monsters, get their shortest routes to all exits
// then bfs on A and find all routes to exit, then compare each exit, if there exists ai S.T. ai < Mi, then there is a vaild path

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define p(n) array<int,n>

const int maxN = 1001, INF = 1e9;
// wow 6 NxN arrays
int n,m,dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1},Mdis[maxN][maxN],Adis[maxN][maxN],p[maxN][maxN];
bool Mvisited[maxN][maxN],Avisited[maxN][maxN];
char g[maxN][maxN], dc[4] = {'D','R','U','L'};
queue<p(2)> q;
p(2) A = {0,0};

bool e(int i, int j){
    return -1<i&&i<n&&-1<j&&j<m&&g[i][j] != '#';
}
bool v(int i, int j){
    return i==0||i==n-1||j==0||j==m-1;
}

void Mbfs(){
    // multi-source bfs from the monsters
    // need to set all Mdis as INF
    while(!q.empty()){
        p(2) node = q.front();
        q.pop();
        int x = node[0], y = node[1];
        for (int i=0;i<4;i++){
            // checks valid and visited
            if (e(x+dx[i],y+dy[i]) && (!Mvisited[x+dx[i]][y+dy[i]])){
                Mvisited[x+dx[i]][y+dy[i]] = true;
                Mdis[x+dx[i]][y+dy[i]] = 1 + Mdis[x][y];
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }
    return;
}

void Abfs(){
    // bfs from A to all exits
    q.push(A);
    while(!q.empty()){
        p(2) node = q.front();
        q.pop();
        int x = node[0], y = node[1];
        // if it is on the boundary, since e(x+dx,y+dy) filters out all '#' then all x,y that satisfy v(x,y) is a vaild exit
        // if monsters need strictly more steps than A, exit is possible 
        if (v(x,y) && Adis[x][y] < Mdis[x][y]){
            vector<char> ch;
            cout << "YES\n" << Adis[x][y] << '\n';
            while (!(x == A[0] && y == A[1])){
                int v = p[x][y];
                ch.push_back(dc[v]);
                x -= dx[v];
                y -= dy[v];
            }
            while(!ch.empty()){
                cout << ch.back();
                ch.pop_back();
            }
            cout << '\n';
            return;
        }

        for (int i=0;i<4;i++){
            // checks valid and visited
            if (e(x+dx[i],y+dy[i]) && (!Avisited[x+dx[i]][y+dy[i]])){
                Avisited[x+dx[i]][y+dy[i]] = true;
                Adis[x+dx[i]][y+dy[i]] = 1 + Adis[x][y];
                q.push({x+dx[i],y+dy[i]});
                p[x+dx[i]][y+dy[i]] = i;
            }
        }
    }
    cout << "NO\n";
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            Mdis[i][j] = INF;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> g[i][j];
            if (g[i][j] == 'M'){
                g[i][j] = '.';
                Mdis[i][j] = 0;
                Mvisited[i][j] = true;
                q.push({i,j});
            }
            if (g[i][j] == 'A'){
                g[i][j] = '.';
                Avisited[i][j] = true;
                A = {i,j};
            }
        }
    }
    Mbfs();
    Abfs();
    return 0;
}
