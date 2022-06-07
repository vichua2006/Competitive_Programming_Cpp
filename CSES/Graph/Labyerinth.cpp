// bfs, seems standard, put memo statement inside the enqueue for loop, because that's appearently a whole lot faster??

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
const int maxN = 1e3+1;

int n,m, dx[] = {1,0,-1,0},dy[] = {0,1,0,-1}, p[maxN][maxN];
char g[maxN][maxN], dc[4] = {'D','R','U','L'};
pii start, target;

bool e(int i,int j){
    return 0<=i&&i<n&&0<=j&&j<m&&g[i][j]=='.';
}

void solve(){
    queue<pii> q;
    g[start.first][start.second] = '#';
    q.push({start.first,start.second});
    while (!q.empty()){
        pii node = q.front();
        q.pop();
        int x = node.first, y = node.second;
        // g[x][y] = '#'
        // causes TLE
        if (x == target.first && y == target.second){
            break;
        }
        for (int i=0;i<4;i++){
            if (e(x+dx[i],y+dy[i])){
                q.push({x+dx[i],y+dy[i]});
                p[x+dx[i]][y+dy[i]] = i;
                g[x+dx[i]][y+dy[i]] = '#';
            }
        }
    }
    if (g[target.first][target.second] == '#'){

        vector<char> ch;
        int x = target.first, y = target.second;
        while (x != start.first || y != start.second){
            int v = p[x][y];
            ch.push_back(dc[v]);
            x -= dx[v];
            y -= dy[v];
            
        }
        reverse(ch.begin(),ch.end());
        cout << "YES" << '\n' << ch.size() << '\n';
        for (char a: ch) cout << a;
        cout << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
    
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> g[i];
        for (int j=0;j<m;j++){
            if (g[i][j] == 'A'){
                start = {i,j};
                g[i][j] = '.';
            }
            if (g[i][j] == 'B'){
                target = {i,j};
                g[i][j] = '.';
            }
        }
    }
    solve();
    return 0;
}