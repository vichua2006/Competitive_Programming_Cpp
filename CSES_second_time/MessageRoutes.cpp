#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
int N,M,dis[maxN],p[maxN];
bool visited[maxN];
vector<int> g[maxN];

void bfs(){
    queue<int> q;
    dis[1] = 0,p[1] = -1;
    visited[1] = 1;
    q.push(1);
    while (q.size()){
        int v = q.front();q.pop();
        for (int a:g[v]){
            if (!visited[a]){
                visited[a] = 1;
                q.push(a);
                dis[a] = dis[v]+1;
                p[a] = v;
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
        int a,b; cin >> a >> b;
        g[a].push_back(b),g[b].push_back(a);
    }
    bfs();
    if (!dis[N]){
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> ans;
        int k = N;
        while (k!=-1) ans.push_back(k),k = p[k];
        reverse(ans.begin(),ans.end());
        cout << dis[N]+1 << '\n';
        for (int a:ans) cout << a << ' ';
    }
    return 0;
}