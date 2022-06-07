// pretty the same as static min query, except an additional function that updates the tree at O(logn)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,Q,K=1;
vector<int> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void compute_tree(int n){
    if (n >= K) return;
    compute_tree(2*n), compute_tree(2*n + 1);
    tree[n] = min(tree[2*n],tree[2*n + 1]);
    return;
}

int find_min(int a, int b){
    a--,b--;
    a += K, b += K;
    int ans = INF;
    while (a <= b){
        if (a%2 == 1) ans = min(ans,tree[a]), a += 1;
        if (b%2 == 0) ans = min(ans,tree[b]), b -= 1;
        a /= 2, b /= 2;
    }
    return ans;
}

void update_tree(int k, int u){
    // updates the value at position k to u
    k += K - 1;
    tree[k] = u;
    // update each level
    for (k /= 2;k >= 1; k /= 2){
        tree[k] = min(tree[2*k],tree[2*k + 1]);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    while (K < N) K *= 2;
    tree.resize(2*K);
    for (int i=0;i<N;i++) cin >> tree[K+i];
    compute_tree(1);
    for (int i=0;i<Q;i++){
        int a,b,c; cin >> a >> b >> c;
        if (a == 2) cout << find_min(b,c) << '\n';
        else update_tree(b,c);
    }
    return 0;
}