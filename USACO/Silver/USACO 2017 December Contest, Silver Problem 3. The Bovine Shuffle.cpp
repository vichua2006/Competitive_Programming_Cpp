/*

this is basically forms a functional graph. The only postitons that will always have cows are positions, or nodes,
that are in a cycle.

thus, we simply need to find all the cycles in the graph, and add together the number of components in each

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, cnt = 0;
// ne[i] denotes the next position for cow in position i
int ne[maxN];
bool vis[maxN], act[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int cycle_count(int x){
    // count the number of nodes in the cycle that x is in
    int s = x;
    int cnt = 1;
    while (ne[x] != s) x = ne[x], cnt ++ ;
    return cnt;
}

void dfs(int curr){
    if (vis[curr]){
        if (act[curr]) cnt += cycle_count(curr);
        return ;
    }

    vis[curr] = 1, act[curr] = 1;
    dfs(ne[curr]);
    act[curr] = 0;

    return ;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO("shuffle");  

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> ne[i];

    for (int i=1;i<N+1;i++){
        if (!vis[i]) dfs(i);
    }

    cout << cnt << '\n';

    return 0;
}