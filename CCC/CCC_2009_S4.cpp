/*

dikjstra from city d to all cities, then go over all pencil cities and find the cheapest one

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M, K, D;
int arr[maxN], dis[maxN], visited[maxN];
vector<ar<int,2>> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dikjstra(){
    priority_queue<ar<int,2>, vector<ar<int,2>>, greater<ar<int,2>>> pq;
    memset(dis, 0x3f, sizeof(dis));
    dis[D] = 0;
    pq.push({0,D});
    while (pq.size()){
        auto node = pq.top(); pq.pop();
        int c = node[0], v = node[1];
        if (visited[v]) continue;
        visited[v] = 1;

        // cout << v << '\n';

        for (ar<int,2> a: g[v]){
            int nc = a[0], nv = a[1];
            if (dis[nv] > c + nc){
                dis[nv] = c + nc;
                pq.push({c + nc, nv});
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
        int a,b,c; cin >> a >> b >> c;
        g[a].push_back({c,b}), g[b].push_back({c,a});
    }
    cin >> K;
    memset(arr, 0x3f, sizeof(arr));
    for (int i=0;i<K;i++){
        int a,b; cin >> a >> b;
        arr[a] = b;
    }
    cin >> D;
    dikjstra();
    int ans = INF;
    for (int i=1;i<N+1;i++) ans = min(ans, dis[i] + arr[i]);
    cout << ans << '\n';
    return 0;
}