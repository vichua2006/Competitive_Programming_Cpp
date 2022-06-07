// couting how many strongly connected components there are
// same logic as flight route check, do two dfs, one on graph,
// another with revered edges to find the SCCs
// first time through, tp sort the graph, asking: where can we reach from node i?. 
// tp makes sure that all nodes that can be reached from i will be behind i
// second time, reverse the edges; what node can reach node i?
// all nodes u,v S.T. u -> v and v -> u form a SCC
// we follow the tp sorted order because for any node a,b where a is infront of b in tp sort, and from reverse-edge dfs, we find 
// that b can also reach a, it guarentees that a -> b and b -> a, since, if only the latter was true, then b would be in front
// of a in the tp sort, but a is in front of b, so there must be a path from a to b and b to a;
// with the above mentioned logic, it also ensures that no node of a SCC is left out.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,scc[maxN],visited[maxN];
vector<int> gout[maxN],gin[maxN],tp;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int curr, vector<int> g[maxN], int v[maxN], int k, bool do_tp_sort){
    if (v[curr] > 0) return;
    // being lazy here; this will allow this function to be used twice for 
    // somewhat different purposes. k will be 1 during first dfs and the group number in the second
    v[curr] = k;
    for (int a:g[curr]){
        dfs(a,g,v,k,do_tp_sort);
    }
    if (do_tp_sort) tp.push_back(curr);
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        gout[a].push_back(b), gin[b].push_back(a);
    }
    // okay, this isn't really a tp sort since the graph is not guarenteed to be DAG, 
    // but records the finish time of each node and orders them from least to greatest; has similar properties to tp
    for (int i=1;i<N+1;i++){
        // k is set to 1
        if (!visited[i]) dfs(i,gout,visited,1,1);
    }
    int group = 0;
    while(tp.size()){
        int node = tp.back(); tp.pop_back();
        // group is used to distinct between SCCs;
        if (scc[node] == 0){
            group += 1;
            dfs(node,gin,scc,group,0);
        }
    }
    cout << group << '\n';
    for (int i=1;i<N+1;i++) cout << scc[i] << (i == N?'\n':' ');
    return 0;
}