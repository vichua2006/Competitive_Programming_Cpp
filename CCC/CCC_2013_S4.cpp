//directed graph, if a > b, g[b].push_back(a)
//start to search from p and q, if q is found first, then q > p, if p is found first, then p > q, else unknown

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 1e6+1,maxM = 1e7;

int n,m,p,q,visited[maxN];
vector<int> g[maxN];

bool dfs(int x, int e){
    if (x == e) return true;
    if (visited[x]) return false;
    visited[x] = true;
    for (int a: g[x]){
        if (dfs(a,e)) return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        g[b].push_back(a);
    }
    cin >> p >> q;
    if (dfs(q,p)) cout << "yes" << '\n';
    else{
        for (int i=1;i<n+1;i++) visited[i] = false;
        if (dfs(p,q)) cout << "no" << '\n';
        else cout << "unknown" << '\n';
    }
    return 0;
}