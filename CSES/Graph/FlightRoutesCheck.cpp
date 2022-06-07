// my first strongly connected problem
// it is basically connectivity check for directed graphs
// for this one, we are checking to see if the whole graph is strongly connected
// idea is that we do dfs once starting at node 1, keeping tract of a visited array
// if visited[i] = true for all i, then it means that node 1 can go to every other node
// then, we REVERSE the edges of the graph and do another dfs search from 1
// if visited[i] = true for all i again, it means that every node can go to node 1
// so node 1 can go to every node, and each node can also go back to node 1
// for every node a,b, a can go to 1 and then go to b, which means that it is strongly connected
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M;
bool visited1[maxN],visited2[maxN];
// two graphs; one stores the edges going into a node, the other the edges that goes out to other nodes
vector<int> gout[maxN],gin[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int curr,vector<int> g[maxN],bool visited[maxN]){
    // performs dfs
    if (visited[curr]) return;
    visited[curr] = true;
    for (int a:g[curr]){
        dfs(a,g,visited);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        gout[a].push_back(b);
        gin[b].push_back(a);
    }
    dfs(1,gout,visited1),dfs(1,gin,visited2);
    for (int i=1;i<N+1;i++){
        // if i can't be reached through 1
        if(!visited1[i]){
            cout << "NO\n" << 1 << ' ' << i << '\n';
            return 0;
        }
        // if 1 can be reached from i
        if(!visited2[i]){
            cout << "NO\n" << i << ' ' << 1 << '\n';
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}