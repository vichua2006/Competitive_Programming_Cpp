/*
either bfs or backtracking
okay so backtracking goes beyond TLE (30+ seconds)
bfs then, in a second version
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

char b[100][100],xcells[100][100];
map<pair<int,int>,int> exits;
int n,m;

void solve(int x,int y,int step){
    char ch = b[x][y];
    if (ch == 'W' || ch == 'X') return;
    //                                 -conveyors moves you one extra cell in that direction
    if (ch == 'U' || ch == 'R' || ch == 'L' || ch == 'D'){
        b[x][y] = 'X';
        //                             -and ofc i mess up the directions
        solve(x + int(ch == 'D') - int(ch == 'U'),y + int(ch == 'R') - int(ch == 'L'),step);
        b[x][y] = ch;
    }
    else{
        if (xcells[x][y]) return;
        if (ch == '.') exits[{x,y}] = min(exits[{x,y}],step);

        b[x][y] = 'X';
        solve(x+1,y,step+1);
        solve(x-1,y,step+1);
        solve(x,y-1,step+1);
        solve(x,y+1,step+1);
        b[x][y] = ch;
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
    solve(sx,sy,0);
    for (auto p:exits){
        if (p.second == INF) cout << -1 << '\n';
        else cout << p.second << '\n';
    }

    return 0;
}