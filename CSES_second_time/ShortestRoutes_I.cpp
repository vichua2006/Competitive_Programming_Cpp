#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
int N,M;
ll dis[maxN];
bool visited[maxN];
vector<ar<ll,2>> g[maxN];

void dijkstra(){
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    pq.push({0,1});
    while (pq.size()){
        ar<ll,2> node = pq.top();pq.pop();
        ll c = node[0],v = node[1];
        if (visited[v]) continue;
        visited[v] = 1;
        for (ar<ll,2> a:g[v]){
            ll nc = a[0],nv = a[1];
            if (dis[nv]> c+nc){
                dis[nv] = c+nc;
                pq.push({c+nc,nv});
            }
        }
    }
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        ll a,b,c; cin >> a >> b >> c;
        g[a].push_back({c,b});
    }
    dijkstra();
    for (int i=1;i<N+1;i++) cout << dis[i] << ' ';
    return 0;
}