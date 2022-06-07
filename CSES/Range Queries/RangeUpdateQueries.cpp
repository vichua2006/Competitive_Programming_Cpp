// uses difference array
// for array a1,a2,a3,a4..an
// its difference array is:
// a1-0,a2-a1,a3-a2,a4-a3.....,an-a(n-1)
// instrestingly enough, the difference array's prefix sum array is the original array
// then, range update becomes updating 2 values, and single queries becomes finding sum of the difference array
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,Q,arr[maxN],K=1;
vector<ll> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void compute_tree(ll r){
    // compute tree that has root r
    // check if r is array element
    if (r >= K) return;
    compute_tree(2*r), compute_tree(2*r + 1);
    // need prefix sum, so calculate sum
    tree[r] = tree[2*r] + tree[2*r + 1];
    return;
}

void update_tree(ll k, ll u){
    // update sum value here
    k += K-1;
    tree[k] += u;
    for (k/=2;k>=1;k/=2){
        tree[k] = tree[2*k] + tree[2*k + 1];
    }
    return;
}

ll find_sum(ll a,ll b){
    // find the sum of interval [a,b]
    // but in this case, a will always be 1
    a += K-1, b += K-1;
    ll s = 0;
    while (a <= b){
        // a needs to be a left child, b needs to be a right child
        if (a%2 == 1) s += tree[a], a += 1;
        if (b%2 == 0) s += tree[b], b -= 1;
        a /= 2, b /= 2;
    }
    return s;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
    cin >> N >> Q;
    for (int i=1;i<N+1;i++) cin >> arr[i];
    // construct tree
    while(K < N) K *= 2;
    tree.resize(2*K);
    // construct difference array, since arr[0] = 0 (not used), it works nicely
    // index 1 to K-1 are tree nodes, index K to 2K are array elements
    for (int i=1;i<N+1;i++) tree[i+K-1] = arr[i]-arr[i-1];
    compute_tree(1);

    for (int i=0;i<Q;i++){
        ll d; cin >> d;
        if (d == 1){
            ll a,b,u; cin >> a >> b >> u;
            // in the array, the difference between arr[a]-arr[a-1] increase by u
            // and arr[b+1]-arr[b] would decrease by u
            // therefore, dif[a] += u, dif[b+1] -= u
            update_tree(a,u);
            // b+1 might go past the indexing of the array, in which case, it is not needed
            if (b < N) update_tree(b+1,-u);
        }
        else{
            ll p; cin >> p;
            cout << find_sum(1,p) << '\n';
        }
    }
    return 0;
}