#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,p[maxN][maxN],visited[maxN][maxN],dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
char g[maxN][maxN],dc[4] = {'D','R','U','L'};
ar<int,2> A,B;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool e(int x,int y){
    return 1<=x&&x<=N&&1<=y&&y<=M&&(!visited[x][y])&&g[x][y]=='.';
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            cin >> g[i][j];
            if (g[i][j]=='A') A = {i,j},g[i][j] = '.';
            if (g[i][j]=='B') B = {i,j},g[i][j] = '.';
        }
    }
    queue<ar<int,2>> q;
    q.push(A),visited[A[0]][A[1]] = 1,p[A[0]][A[1]] = -1;
    while (q.size()){
        ar<int,2> node = q.front();q.pop();
        int x = node[0],y = node[1];
        if (x==B[0]&&y==B[1]){
            string ans;
            while (p[x][y]!=-1){
                ans.push_back(dc[p[x][y]]);
                int nx = x-dx[p[x][y]],ny = y-dy[p[x][y]];
                x = nx,y = ny;
            }
            reverse(ans.begin(),ans.end());
            cout << "YES\n" << ans.size() << '\n'<< ans << '\n';
            return 0;
        }
        for (int i=0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if (e(nx,ny)){
                visited[nx][ny] = 1;
                p[nx][ny] = i;
                q.push({nx,ny});
            }
        }
    }
    cout << "NO\n";
    return 0;
}