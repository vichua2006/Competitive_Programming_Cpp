#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M;
bool visited[maxN],act[maxN],is_valid = 1;
vector<int> g[maxN],tp;

void dfs(int curr){
    visited[curr] = 1, act[curr] = 1;
    for (int a:g[curr]){
        if (visited[a]){
            if (act[a]){
                cout << "IMPOSSIBLE\n";
                is_valid = 0;
            }
            continue;
        } else {
            dfs(a);
        }
    }
    tp.push_back(curr);
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
    }
    for (int i=1;i<N+1;i++){
        if (!visited[i]) dfs(i);
    }
    if (!is_valid){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(tp.begin(),tp.end());
    for (int a: tp) cout << a << ' ';
    return 0;
}