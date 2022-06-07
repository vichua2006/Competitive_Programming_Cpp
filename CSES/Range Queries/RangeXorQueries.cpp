// basically the same as dyanmic min query but with sum
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,Q,K=1;
vector<ll> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void compute_tree(ll r){
    if (r >= K) return;
    compute_tree(2*r),compute_tree(2*r + 1);
    tree[r] = tree[2*r]^tree[2*r + 1];
    return;
}

ll find_sum(ll a, ll b){
    a += K-1, b += K-1;
    ll s = 0;
    // go up the tree, merging together nodes that do not belong in the next level
    while(a<=b){
        if (a%2 == 1) s ^= tree[a], a += 1;
        if (b%2 == 0) s ^= tree[b], b -= 1;
        a /= 2, b /= 2;
    }
    return s;
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    // construct segmented tree
    while (K<N) K = K<<1;
    tree.resize(2*K,0);
    for (int i=0;i<N;i++) cin >> tree[i+K];
    compute_tree(1);
    // take in queries
    for (int i=0;i<Q;i++){
        ll b,c; cin >> b >> c;
        cout << find_sum(b,c) << '\n';
    }
    return 0;
}