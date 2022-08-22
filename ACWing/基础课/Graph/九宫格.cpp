/*

next time with state representation, go with the simplier data structure

vector<vector<int>> --> vector<int> (index just goes from v[i][j] to v[n*i+j])

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 100 + 1,maxM = 101,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
string s;
unordered_map<string,int> d;

bool sol(string &ans){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (ans[i*3+j]!=char('0'+3*i+j+1)) return 0;
        }
    }
    return 1;
}

int bfs(){
    queue<string> q;
    q.push(s),d[s] = 0;
    while (q.size()){
        string node = q.front();q.pop();
        int x,y;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (node[3*i+j]=='9'){
                    x = i,y = j;
                }
            }
        }
        int cnt = d[node];
        if (x==2&&y==2){
            if (sol(node)) return cnt;
        }
        for (int i=0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if (0<=nx&&nx<3&&0<=ny&&ny<3){
                int a = node[3*x+y],b = node[3*nx+ny];
                node[3*x+y] = b,node[3*nx+ny] = a;
                if (d.find(node)==d.end()){
                    d[node] = cnt+1,q.push(node);
                }
                node[3*x+y] = a,node[3*nx+ny] = b;
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    s.resize(9);
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            char a; cin >> a;
            if (a=='x') s[i*3+j] = '9';
            else s[3*i+j] = a;
        }
    }
    cout << bfs() << '\n';
    return 0;
}