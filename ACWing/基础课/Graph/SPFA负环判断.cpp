/*

see this as the continuation of the spfa head comment

by bellman-ford logic, each nodes should only be updated at most N times. Anymore and it is guareeteed to be 
a negative cycle

so, just count the number of times each nodes has been updated?


update:

yes it works, but each time a is updated using b, the shortest path to a now uses cnt[b] + 1 edges
and by the same logic, if a path uses N edges and thus N + 1 nodes, it means that there must be a loop

also, an interesting concept: 超级原点
essentially, creat a fictionous node 0, let it have an (directed) edge of weight 0 to every node

thus, if the search function starts on node 0, it is guarenteed to be able to search all components

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
int dis[maxN], cnt[maxN];
bool vis[maxN], pro[maxN];
vector<ar<int, 2>> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void spfa(int s){
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;

    dis[s] = 0;
    q.push(s);
    vis[s] = 1;
    while (q.size()){
        int v = q.front(); q.pop();
        vis[v] = 0, pro[v] = 1;
        for (auto a : g[v]){
            int nc = a[0], nv = a[1];
            if (dis[nv] > dis[v] + nc){
                dis[nv] = dis[v] + nc;
                cnt[nv] = cnt[v] + 1;
                if (cnt[nv] > N){
                    cout << "Yes\n";
                    exit(0);
                }
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
    for (int i=1;i<N+1;i++) g[0].push_back({0, i});


    // please remember that there might be multiple components
    // or do that thing
    for (int i=1;i<N+1;i++){
        if (!pro[i]) spfa(i);
    }

    cout << "No\n";

    return 0;
}