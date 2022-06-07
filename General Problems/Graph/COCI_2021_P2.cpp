/*

be aware of correctness of the constrains on vairables
this problem gives only n = 70 nodes, yet gives m <= 1e6 edges
and has a limit on the number of edges taken of K <= 1e9

with n <= 70 and directed edges (without self looping and multiple a -> b bs)
there can only be at most 70*69 edges

and since there are only 70 nodes, we go throught at most 69 edges, anymore than that would jus result in loops

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 70+1,INF = 1e9;
ll N,M,K,Q;
ll dis[maxN][maxN],rec[maxN][maxN],g[maxN][maxN];
bool visited[maxN][maxN],computed[maxN];
priority_queue<ar<ll,3>,vector<ar<ll,3>>,greater<ar<ll,3>>> pq;

void dijkstra(ll a){
    memset(visited,0,sizeof(visited)),memset(dis,0x3f,sizeof(dis));
    dis[a][0] = 0;
    pq.push({0,0,a});
    while (pq.size()){
        ar<ll,3> node = pq.top();pq.pop();
        ll c = node[0],r = node[1],v = node[2];
        if (visited[v][r]) continue;
        visited[v][r] = 1;
        for (int nv=1;nv<N+1;nv++){
            ll nc = g[v][nv];
            if (nc&&r+1<=min(K,70LL)&&dis[nv][r+1]>c+nc){
                dis[nv][r+1] = c+nc;
                pq.push({c+nc,r+1,nv});
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    memset(g,0x3f,sizeof(g));
    for (int i=0;i<M;i++){
        ll a,b,c; cin >> a >> b >> c;
        // in matrix form because we can get rid of repeating edges
        g[a][b] = min(g[a][b],c);
    }
    cin >> K >> Q;
    for (int i=0;i<Q;i++){
        ll a,b; cin >> a >> b;
        // memorization 
        if (!computed[a]){
            dijkstra(a);
            for (int j=1;j<N+1;j++){
                ll cnt = 0x3f3f3f3f3f3f3f3f;
                for (int k=1;k<N+1;k++) cnt = min(cnt,dis[j][k]);
                rec[a][j] = cnt;
            }
            computed[a] = 1;
        }
        if (a==b) cout << 0 << '\n';
        else cout << (rec[a][b]>1e18?-1:rec[a][b]) << '\n';
    }
    return 0;
}
