#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 1e5 + 1,maxM = 0,maxK = 10,INF = 1e18, MOD = 1e9 + 7;
ll N,M,K,dis[maxN][maxK];
vector<ar<ll,2>> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dijkstra(){
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
    for (int i=1;i<N+1;i++){
        for (int j=0;j<K;j++){
            dis[i][j] = INF;
        }
    }
    pq.push({0,1});
    while (pq.size()){
        ar<ll,2> node = pq.top(); pq.pop();
        ll c = node[0],v = node[1];
        if (dis[v][K-1] < c) continue;
        for (ar<ll,2> a:g[v]){
            ll nc = a[0],nv = a[1];
            if (dis[nv][K-1]>c+nc){
                dis[nv][K-1] = c+nc;
                pq.push({dis[nv][K-1],nv});
                sort(dis[nv],dis[nv]+K);
            }
        }
    }
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> K;
    for (int i=0;i<M;i++){
        int a,b,c; cin >> a >> b >> c;
        g[a].push_back({c,b});
    }
    dijkstra();
    for (int i=0;i<K;i++) cout << dis[N][i] << (i==K-1?'\n':' ');
    return 0;
}