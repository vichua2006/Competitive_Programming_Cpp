/*

there's actually meaning to the number of loops the algorithm has gone through

suppose we have looped k time. It indicates the current dis[i] denotes the shortest path using no more than k
edges from the starting node

under this definition, suppose there was still a dis[i] being updated on the nth loop

that would mean that this shorest path consists of N edges, and thus N + 1 nodes. Since we only have N nodes,
by pigeonhole principle, there must be two of the same nodes in the path, which means that there must be a cycle

for shortest paths, it would be a negative cycle
for longest paths, it would be positive cycle

it is obvious that the time complexity is O(NM)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M, K;
ar<int, 3> ed[maxN];
ll dis[maxN], backup[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void bmf(){
    for (int i=0;i<M;i++){
        auto &e = ed[i];
        int a = e[0], b = e[1], c = e[2];
        dis[b] = min(dis[b], backup[a] + c);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> K;
    for (int i=0;i<M;i++) cin >> ed[i][0] >> ed[i][1] >> ed[i][2];
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for (int i=0;i<K;i++){
        // for this particular problem, we have to copy dis array
        // for each loop of bmf
        // to prevent the situation where, during the same, loop,
        // node A was updated (and thus increased its edge count),
        // and then A was used to update B
        // this no longer guarentees that the result uses no more than K loops
        memcpy(backup, dis, sizeof(dis));
        bmf();
    }

    cout << (dis[N] > INF ? -1 : dis[N]) << '\n';

    return 0;
}