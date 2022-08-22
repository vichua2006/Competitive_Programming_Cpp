/*

proof of dijkstra's correctness

suppose we have visited k nodes

let u be the first unvisited node with the smallest value of dis[u],
and let v be the visited node such that dis[u] = dis[v] + length(u, v)

suppose there was a shorter path to u using other unvisited nodes, and w was the first unvisited node on that path, then
since all weights are non-negative, it must mean that dis[w] < dis[u]. However, this contradicts the assumption that dis[u] was the smallest 
amongst unvisited nodes

similarly, if there was a shorter path to u using only visited nodes, then let w be the last second last node (right before u) on that path
that would mean dis[w] + length(u, w) < dis[v] + length(u, v). However, if that was the case, then dis[u] would have been updatd when processing w, 
but instead, it was updated by node v, which creates a contradiction. Hence, dis[u] is the shortest path


and a more fitting understanding of what visited array actually means:
vis[i] denotes whether or not the shortest distance to i is already determined (certain)

hence, in bfs, the condition can be placed inside the for loop, but it dijkstra, it
has to be after poping out a new node

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
bool vis[maxN];
int dis[maxN];
vector<ar<int, 2>> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dijkstra(){
    priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    pq.push({0, 1});
    while (pq.size()){
        auto n = pq.top(); pq.pop();
        int c = n[0], v = n[1];
        if (vis[v]) continue;
        vis[v] = 1;
        for (auto a : g[v]){
            int nc = a[0], nv = a[1];
            if (dis[nv] > dis[v] + nc){
                dis[nv] = dis[v] + nc;
                pq.push({dis[nv], nv});
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
    dijkstra();
    cout << (dis[N] > INF ? -1 : dis[N]) << '\n';
    return 0;
}