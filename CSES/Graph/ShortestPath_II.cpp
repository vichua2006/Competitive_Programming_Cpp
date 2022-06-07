//floyd-warshell algorithm (lots of queries, only 500 nodes)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e15;

int n,m,q;
vector<pair<int,int>> queries;
ll dis[501][501];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    //              -initialize array
    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    //              -mark known distance
    for (int i=0;i<m;i++){
        ll a,b,c;cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b],c);
        dis[b][a] = min(dis[b][a],c);
    }
    for (int i=0;i<q;i++){
        int a,b;cin >> a >> b;
        queries.push_back({a,b});
    }
    //              -O(n^3) complexity, using each node as an intermediate nodes to update minimum distance
    for (int node=1;node<n+1;node++){
        for (int i=1;i<n+1;i++){
            for (int j=1;j<n+1;j++){
                dis[i][j] = min(dis[i][j],dis[i][node]+dis[node][j]);
            }
        }
    }
    for (auto p:queries){
        if (dis[p.first][p.second] == INF) cout << -1;
        else cout << dis[p.first][p.second];
        cout << '\n';
    }
    return 0;
}
