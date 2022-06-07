#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,p[maxN],visited[maxN];
vector<int> g[maxN],cycle;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool dfs(int curr){
    if (visited[curr]==2) return false;
    if (visited[curr]==1){
        cycle.push_back(curr);
        int ans = p[curr];
        while (ans!=curr){
            cycle.push_back(ans);
            ans = p[ans];
        }
        cycle.push_back(curr);
        return true;
    }
    visited[curr] = 1;
    for (int a:g[curr]){
        p[a] = curr;
        if (dfs(a)) return true;;
    }
    visited[curr] = 2;
    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        if (a!=b) g[a].push_back(b);
    }
    for (int i=1;i<N+1;i++){
        if (!visited[i]) p[i] = i,dfs(i);
        if (cycle.size()){
            cout << cycle.size() << '\n';
            for (int i=cycle.size()-1;i>=0;i--) cout << cycle[i] << (i==0?'\n':' ');
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}