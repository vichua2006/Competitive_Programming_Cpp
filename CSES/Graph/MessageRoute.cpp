// bfs with route trancing, seems as if we never get to use dictionaries in C++, arrays always suffice and is often better
// DFS/BFS time complexity: https://stackoverflow.com/questions/11468621/why-is-the-time-complexity-of-both-dfs-and-bfs-o-v-e
// so O(V + E)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

const int maxN = 1e5+1;

int n,m, p[maxN];
bool visited[maxN];
vector<int> g[maxN];

void solve(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    p[1] = 1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for (int v: g[node]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
                p[v] = node;
            }
        }
    }
    vector<int> path;
    if (visited[n]){
        int temp = n;
        while(temp != 1){
            path.push_back(temp);
            temp = p[temp];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        cout << path.size() << '\n';
        for (int a: path) cout << a << ' ';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve();
    return 0;
}