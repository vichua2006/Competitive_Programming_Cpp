#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 14e6 + 1, INF = 1e9, MOD = 1e9 + 7;
vector<int> g[maxN];
bitset<maxN> visited;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool can_escape(int M, int N, std::vector<std::vector<int>> v){
    // just regular iterative dfs, should pass?
    for (int i=1;i<M+1;i++) for (int j=1;j<N+1;j++) g[i*j].push_back(v[i][j]);
    vector<int> st;
    visited[1] = true;
    st.push_back(1);
    while(st.size()){
        int node = st.back(); st.pop_back();
        for (int a: g[node]){
            if (!visited[a]){
                if (a == M*N) return true;
                visited[a] = true;
                st.push_back(a);
            }
        }
    }
    return false;
}

// int main(){
//     cin.tie(0);
//     cin.sync_with_stdio(0);
//     vector<vector<int>> t = 
//     {{0, 0, 0, 0, 0},
//     {0, 3, 10, 8, 1},
//     {0, 1, 11, 12, 12},
//     {0, 6, 2, 3, 9}};
//     cout << can_escape(3, 4, t) << '\n';
//     return 0;
// }