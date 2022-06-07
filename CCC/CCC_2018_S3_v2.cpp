//reading input and majority of main() remains the same 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

char b[100][100],xcells[100][100];
map<pair<int,int>,int> exits;
int n,m,dx[] = {1,0,-1,0},dy[] = {0,-1,0,1};

void bfs(pair<int,int> start){
    list<pair<int,int>> q;
    int x,y,step = 0;
    char ch;
    pair<int,int> node;
    q.push_back(start);
    q.push_back({INF,INF});
    while(q.size() > 1){
        node = q.front();
        x = node.first,y = node.second;
        q.pop_front();
    
        if (x == INF && y == INF){step += 1; q.push_back({INF,INF}); continue;}
        ch = b[x][y];
        if (ch == 'X' || ch == 'W') continue;
        if (ch == 'U' || ch == 'R' || ch == 'L' || ch == 'D'){
            //       -conveyors moves you one extra cell in that direction without counting that step, annoying
            b[x][y] = 'X';
            q.push_front({x + int(ch == 'D') - int(ch == 'U'),y + int(ch == 'R') - int(ch == 'L')});
            continue;
        }
        if (xcells[x][y]) continue;
        if (ch == '.') exits[{x,y}] = min(exits[{x,y}],step);
        b[x][y] = 'X';
        for (int i=0;i<4;i++){
            if (b[x+dx[i]][y+dy[i]] != 'W' && b[x+dx[i]][y+dy[i]] != 'X'){
                q.push_back({x+dx[i],y+dy[i]});
            }
        }
    }
    return;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string line;
    vector<pair<int,int>> cam;
    int sx,sy;
    //                   -reads in grid
    for (int i=0;i<n;i++){
        cin >> line;
        for (int j=0;j<m;j++){
            if (line[j] == 'S') sx = i,sy = j;
            if (line[j] == '.') exits[{i,j}] = INF;
            if (line[j] == 'C') cam.push_back({i,j});
            b[i][j] = line[j];
        }
    }
    //                     -maps out cells seen by cameras
    for (auto c:cam){
        int x = c.first,y = c.second,u = 0,l = 0,d = 0,r = 0;
        while (b[x][y+u] != 'W'){xcells[x][y+u] = 1; u += 1;}
        while (b[x][y-d] != 'W'){xcells[x][y-d] = 1; d += 1;}
        while (b[x+r][y] != 'W'){xcells[x+r][y] = 1; r += 1;}
        while (b[x-l][y] != 'W'){xcells[x-l][y] = 1; l += 1;}
    }
    bfs({sx,sy});
    for (auto p:exits){
        if (p.second == INF) cout << -1 << '\n';
        else cout << p.second << '\n';
    }
    return 0;
}