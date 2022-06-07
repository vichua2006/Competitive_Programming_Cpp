// seems to be a variation of dijkstra's algorithm
// first attempt: use time as dijkstra variable, keep tract of k, and erase ships with hull h < 1
// nope
// second attempt: let dist[i][j] be the time needed to go to node i with sustaining j units of damage, 
// fill out grid and then print(min(dist[B]))
// yahooh!

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define p(n) array<int,n>
// this seems to suffice and is probably easier to work with than pair<int,pair<int,int>>

const int maxN = 2e3 + 1, maxK = 2e2 + 1, INF = 1e10;

int k,n,m,A,B,dis[maxN][maxK];
vector<p(3)> g[maxN];
bool visited[maxN][maxK];

void solve(){
    // initialize dis
    for (int i=0;i<n+1;i++){
        for (int j=0;j<k+1;j++){
            dis[i][j] = INF;
        }
    }
    // shortest route to A, sustaining 0 cm of damage, requires 0 units time
    dis[A][0] = 0;
    priority_queue<p(3),vector<p(3)>,greater<p(3)>> q;
    q.push({0,0,A});
    while (!q.empty()){
        // t,h,node
        p(3) curr_node = q.top();
        q.pop();
        // visited is not nessesary, but it saves a lot of time
        if (visited[curr_node[2]][curr_node[1]]) continue;
        visited[curr_node[2]][curr_node[1]] = true;
        for (p(3) next_node: g[curr_node[2]]){
            // if the damage is strictly less than k
            if (curr_node[1]+next_node[1] < k){
                // if dist[i][j+new_damage] > dist[k][j] + time_needed_to_get_to_node_i
                if (dis[next_node[2]][curr_node[1]+next_node[1]] > dis[curr_node[2]][curr_node[1]] + next_node[0]){
                    dis[next_node[2]][curr_node[1]+next_node[1]] = dis[curr_node[2]][curr_node[1]] + next_node[0];
                    // t,h,node
                    q.push({dis[next_node[2]][curr_node[1]+next_node[1]],curr_node[1]+next_node[1],next_node[2]});
                }
            }
        }
    }
    int ans = INF;
    for (int i=0;i<k;i++){
        ans = min(ans,dis[B][i]);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> k >> n >> m;
    for (int i=0;i<m;i++){
        int a,b,t,h; cin >> a >> b >> t >> h;
        g[a].push_back({t,h,b});
        g[b].push_back({t,h,a});
    }
    cin >> A >> B;
    solve();
    return 0;
}