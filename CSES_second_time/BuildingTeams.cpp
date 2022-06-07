// coloring graph, if there is friendship between two, then they must be colored differently
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,c[maxN];
bool visited[maxN],valid = true;
vector<int> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int curr,bool clr){
    visited[curr] = 1,c[curr] = clr;
    for (int a: g[curr]){
        if (visited[a]&&c[a]==c[curr]){
            valid = 0;
            return;
        }
        if (!visited[a]){
            dfs(a,clr^1);
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
        int a,b; cin >> a >> b;
        g[a].push_back(b),g[b].push_back(a);
    } 
    for (int i=1;i<N+1;i++){
        if (!visited[i]) dfs(i,1);
        if (!valid){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for (int i=1;i<N+1;i++) cout << c[i]+1 << (i==N?'\n':' ');
    return 0;
}