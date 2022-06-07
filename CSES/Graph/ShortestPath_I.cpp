//my first dijkstra problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

int n,m;
ll dis[200000];
bool visited[200000];
unordered_map<ll,vector<pair<ll,ll>>> d;
priority_queue<pair<ll,ll>> q;

void solve(){
    for (int i=1;i<n+1;i++) dis[i] = INF;
    dis[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        ll u = q.top().second; q.pop();
        // this is not nessesary, but it saves time, as once reached, 
        // the node's value is guaranteed to be shortest and won't be changed again
        if (visited[u]) continue;
        visited[u] = true;
        for (auto p:d[u]){
            ll w = p.first, v = p.second;
            if (dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                q.push({-dis[v],v});
            }
        }
    }
    for (int i=1;i<n+1;i++) cout << dis[i] << ' ';
    cout << '\n';

}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll a,b,w;cin >> a >> b >> w;
        d[a].push_back({w,b});
    }
    solve();
    return 0;
}