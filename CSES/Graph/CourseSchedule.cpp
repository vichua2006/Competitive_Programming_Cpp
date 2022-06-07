//topological sort, if there's a cycle, then it is impossible (A -> B -> C -> A. A needs to be completed before C, but C needs to be completed before A)

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1e5+1;

int n,m,state[maxN];
vector<int> g[maxN],t_sort;

bool solve(int curr){
    // states: 0 for undiscovered, 1 for discovered, 2 for processed
    if (state[curr] == 1) return true;
    if (state[curr] == 2) return false;
    state[curr] = 1;
    for (int a: g[curr]){
        if (solve(a)) return true;
    }
    state[curr] = 2;
    t_sort.push_back(curr);
    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i=1;i<n+1;i++){
        if (!state[i]){
            if (solve(i)){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for (int i=t_sort.size()-1;-1<i;i--){
        cout << t_sort[i] << ' ';
    }
    return 0;
}