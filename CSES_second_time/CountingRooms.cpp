#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 1e3 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
ll N,M,dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
bool visited[maxN][maxN];
char g[maxN][maxN];

bool e(int x,int y){
    return 1<=x&&x<=N&&1<=y&&y<=M&&(!visited[x][y])&&g[x][y]=='.';
}

void dfs(int x,int y){
    visited[x][y] = 1;
    for (int i=0;i<4;i++){
        int nx = x+dx[i],ny = y+dy[i];
        if (e(nx,ny)) dfs(nx,ny);
    }
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            cin >> g[i][j];
        }
    }
    int cnt = 0;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            if (e(i,j)) dfs(i,j),cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}