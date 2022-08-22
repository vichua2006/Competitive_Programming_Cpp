/*

spfa is baiscally optimized bellman-ford that looks like bfs/dijkstra

realize that in bellman-ford, it occured often that an unupdated node was used to update another node, which
would have done nothing. Hence, the thought is that we should only use updated nodes to update other nodes.

basically, the difference in the code of spfa and bfs is that:
1. it doesn't have a visited because a node's dis[i] could be updated multiple times
2. it checks to see if going from the current node to its neighbors would yield a better result,
and if it does, pushes it into the queue, to update other nodes will the new smaller value

since it doesn't have visited, still updates one node multiple times. It essentially does the same thing as 
bellman-ford, but more efficiently. Which is why, despite looking similar to dijkstra, it can handel negative weights, 
since its core idea is still to update everything until it can't

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
int dis[maxN];
// here, vis[i] denotes whether or not i is currently in queue, as for spfa, unlike dijkstra, there is no point
// in having multiple of the same nodes in queue at once 
bool vis[maxN];
vector<ar<int, 2>> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void spfa(){
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;

    dis[1] = 0;
    q.push(1);
    vis[1] = 1;
    while (q.size()){
        int v = q.front(); q.pop();
        vis[v] = 0;
        for (auto a : g[v]){
            int nc = a[0], nv = a[1];
            if (dis[nv] > dis[v] + nc){
                dis[nv] = dis[v] + nc;
                // check if node is currently in queue
                if (!vis[nv]){
                    q.push(nv);
                    vis[nv] = 1;
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({c, b});
    }

    spfa();

    int res = dis[N];
    if (res > INF) cout << "impossible\n";
    else cout << res << '\n';

    return 0;
}