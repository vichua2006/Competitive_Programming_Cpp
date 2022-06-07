// finding the diameter of the tree: 2 methods
// 1. dp method, record distance of node furthest to the current node,
// and the longest path that goes through the current node. Method 1 is O(n),
// so slightly faster than 2, but it doesn't store the actual path, juts the length
// 2. dfs from arbritary node and find node furthest away from it. It can be proven
// that such node must be one of the ends of the diameter
// then starting at that node A, dfs again, find furthest node from A, say B.
// now, diameter is AB. A bit slower than previous method, but records paths
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,dis[maxN];
vector<int> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int curr,int pre){
    for (int a:g[curr]){
        if (a!=pre){
            dis[a] = dis[curr] + 1;
            dfs(a,curr);
        }
    }
}

int find_max(){
    int d1 = 0;
    for (int i=1;i<N+1;i++){
        if (dis[i] > dis[d1]) d1 = i;
    }
    return d1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b),g[b].push_back(a);
    }
    dfs(1,0);
    int node = find_max();
    dis[node] = 0;
    dfs(node,0);
    cout << dis[find_max()] << '\n';
    return 0;
}