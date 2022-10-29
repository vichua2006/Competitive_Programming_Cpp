/*

binary lifting, but it is written in a different way

still, anc[i][j] will denote ancestor of i that is 2 ^ j levels higher
d[i] will denote the depth of the ith node from the root node

first, binary jump the nodes to the same level (same depth)
then, keep jumping until they arrive at one level under the their first common ancestor, which is their lca

(this particular problem asks for distance too)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 10, maxM = 19, INF = 1e9, MOD = 1e9 + 7;
int N, Q;
int dep[maxN];
int anc[maxN][maxM];
vector<int> g[maxN];

void dfs(int curr, int pre=0){
    anc[curr][0] = pre;
    for (int i=1;i<19;i++){
        // compute the parents array
        anc[curr][i] = anc[anc[curr][i - 1]][i - 1];
    }
    for (int a: g[curr]){
        if (a ^ pre){
            dep[a] = dep[curr] + 1;
            dfs(a, curr);
        }
    }
}

int lca(int a, int b){
    // returns the lca of node a and node b
    if (dep[a] < dep[b]) swap(a, b);
    // negatives are represented with 2's complement
    // ~i will only be false if i == -1
    for (int i=18;~i;i--){
        if (dep[a] - (1 << i) >= dep[b]){
            a = anc[a][i];
        }
    }
    
    if (a == b) return a;
    for (int i=18;~i;i--){
        if (anc[a][i] ^ anc[b][i]){
            a = anc[a][i], b = anc[b][i];
        }
    }

    return anc[a][0];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=0;i<N-1;i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }

    dfs(1);

    for (int i=0;i<Q;i++){
        int a, b; cin >> a >> b;
        int p = lca(a, b);
        cout << dep[a] + dep[b] - 2* dep[p] << '\n';
    }

    return 0;
}