#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,p[maxN];
bool visited[maxN],act[maxN];
vector<int> g[maxN];

void dfs(int curr,int pre){
    visited[curr] = 1,act[curr] = 1;
    for (int a:g[curr]){
        if (a==pre) continue;
        if (visited[a]){
            if (act[a]){
                vector<int> ans;
                ans.push_back(a);
                while (curr!=a){
                    ans.push_back(curr);
                    curr = p[curr];
                }
                ans.push_back(a);
                reverse(ans.begin(),ans.end());
                cout << ans.size() << '\n';
                for (int a: ans) cout << a << ' ';
                exit(0);
            }
            continue;
        } else {
            p[a] = curr,dfs(a,curr);
        }
    }
    act[curr] = 0;
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<N+1;i++){
        if (!visited[i]) p[i] = i,dfs(i,-1);
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}