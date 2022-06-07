// pretty much CCC 15 S4 but different
// since ci,fi <= 1000, 2d array should still suffice
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e3 + 1, INF = 1e9, MOD = 1e9 + 7;
// dis[i][j] denotes the minimum cost to node i with flow rate j
// dis[i][j] denoting the flow rate with node i and cost of j CAN theoretically work, but f doesn't exceed 1000 while Sum(ci) does, so TLE is inevitable
ll N,M,dis[maxN][maxN];
bool visited[maxN][maxN];
vector<ar<ll,3>> g[maxN];
priority_queue<ar<ll,3>,vector<ar<ll,3>>> pq;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void solve(){
    memset(dis,0x3f,sizeof dis);
    dis[1][1000] = 0; pq.push({1000,0,1});
    while(pq.size()){
        ar<ll,3> node = pq.top(); pq.pop();
        ll f = node[0], c = abs(node[1]), v = node[2];
        if (visited[v][f]) continue;
        visited[v][f] = true;
        for (ar<ll,3> a:g[v]){
            ll nf = a[0], nc = abs(a[1]), nv = a[2];
            if (dis[nv][min(f,nf)] > dis[v][f] + nc){
                dis[nv][min(f,nf)] = dis[v][f] + nc;
                pq.push({min(f,nf),-(dis[v][f] + nc),nv});
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("pump");

    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a,b,c,f; cin >> a >> b >> c >> f;
        // prioritizing flow rate over cost
        // result is, for every flow rate, we get min cost for that flow rate
        g[a].push_back({f,-c,b});
        g[b].push_back({f,-c,a});
    }
    solve();
    int ans = 0;
    for (int i=1;i<1001;i++){
        // go through all 1000 flow rates for n, pick the max one
        int a = i*1e6;
        int b = a/(dis[N][i]);
        ans = max(ans, b);
    }
    cout << ans << '\n';
    return 0;
}