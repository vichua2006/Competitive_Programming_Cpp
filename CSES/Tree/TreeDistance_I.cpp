/*

similar to dp tree diameter, we first want to root the tree arbritarily 
then, for each node, we compute its maximum path to one of its leaf and its maximum path through its parent
and pick the largest one.

To prevent the two being the same paths (see cph for detail), we find both the longest and second longest paths for each node
and just pick the valid path

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int dis[maxN], ans[maxN];
vector<int> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs1(int curr=1, int pre=0){
    // compute longest distance to child for all nodes
    for (int a:g[curr]){
        if (a==pre) continue;
        dfs1(a, curr);
        dis[curr] = max(dis[curr], dis[a] + 1);
    }
}

void dfs2(int curr=1, int pre=0, int pd=-1){
    // current node, parent, longest path from parent (parent distance, path does not include current)
    ans[curr] = max(dis[curr], pd + 1);
    vector<ar<int,2>> paths = {{-1, 0}};
    // needs at least 1 element, prevents index error later on
    for (int a:g[curr]){
        if (a==pre) continue;
        // compute all paths into vector, then sort to get top 2
        paths.push_back({dis[a] + 1, a});
    }
    // must include ALL possible paths from the parent node
    paths.push_back({pd + 1, pre});
    // greater<int> is the type, and greater<int>() is the operator function defined within?
    sort(paths.begin(), paths.end(), greater<ar<int,2>>());
    for (int a: g[curr]){
        if (a==pre) continue;
        // for each child, check if longest path includes that child.
        dfs2(a, curr, a==paths[0][1] ? paths[1][0] : paths[0][0]);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    dfs1();
    dfs2();
    for (int i=1;i<N+1;i++) cout << ans[i] << (i==N ? '\n':' ');
    return 0;
}