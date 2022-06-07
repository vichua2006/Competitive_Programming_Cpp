/*

let d(a,b) denote the distance between two nodes a, b of a rooted tree with root r
let lca(a,b) denote the least common ancestor of a,b

therefore,

    d(a,b) = d(r,a) + d(r,b) - 2*d(r,lca(a,b))

d(r,x) can be quried in O(1) with O(2N-1) precomputation
lca(a,b) can be quried in O(logn) with binary lifting and O(nlogn) recomputation

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 19,INF = 1e9, MOD = 1e9 + 7;
int N, Q, t = 0;
// start/finish time is used to determine if a node is the ancestor of another node
int dis[maxN], ft[maxN], st[maxN];
// log2(2e5) ~ 18
int bin[maxK][maxN];
vector<int> g[maxN];

bool is_anc(int a, int b){
    // node b is parent of a if st[b] < st[a] && ft[b] > ft[a]
    return st[b] <= st[a] && ft[b] >= ft[a];
}

void dfs(int curr, int pre){
    t += 1;
    st[curr] = t, bin[0][curr] = pre;
    for (int a:g[curr]){
        if (a != pre){
            dis[a] = dis[curr] + 1;
            dfs(a, curr);
        }
    }
    t += 1;
    ft[curr] = t;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    // root the tree at node 1
    dfs(1, 1);
    for (int i=1;i<maxK;i++){
        for (int j=1;j<N+1;j++){
            // bin[i][j] denotes the pow(2,i) parent of node j
            bin[i][j] = bin[i-1][bin[i-1][j]];
        }
    }
    for (int i=0;i<Q;i++){
        int a,b; cin >> a >> b;
        if (is_anc(a,b)){
            cout << dis[a] - dis[b] << '\n';
            continue;
        }
        if (is_anc(b,a)) cout << dis[b] - dis[a] << '\n';
        else {
            int p = a;
            for (int q=maxK-1;q>=0;q--){
                // will stop at the tallest node that is not a parent of b
                if (!is_anc(b,bin[q][p])) p = bin[q][p];
            }
            // one more level up
            p = bin[0][p];
            cout << dis[a] + dis[b] - 2*dis[p] << '\n';
        }
    }
    return 0;
}