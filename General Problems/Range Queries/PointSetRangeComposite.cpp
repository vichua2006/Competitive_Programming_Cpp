// given N linear functions f0, f1,f2...fN, process queries:
// 1. given r,l,x, calculate fr-1(fr-2(fr-3(...fl(x)....)
// 2. update function k to cx + d
// just record fx(....f(y)...) for each node in segmented tree

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 5e5 + 1, INF = 1e9, MOD = 998244353;
ll N,Q,K=1;
// 0 is a, 1 is b
vector<ar<ll,2>> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void compute_tree(ll r){
    if (r >= K) return;
    compute_tree(2*r), compute_tree(2*r + 1);
    // calculate fr(x) = f2r+1(f2r(x))
    ll a = tree[2*r][0], b = tree[2*r][1], c = tree[2*r + 1][0], d = tree[2*r + 1][1];
    // i think it's okay to just mod here?
    tree[r][0] = (a*c)%MOD, tree[r][1] = (c*b + d)%MOD;
    return;
}

void update_tree(ll p, ll c, ll d){
    p += (K);
    tree[p][0] = c, tree[p][1] = d;
    for (p/=2;p>=1;p/=2){
        ll a = tree[2*p][0], b = tree[2*p][1], c = tree[2*p + 1][0], d = tree[2*p + 1][1];
        tree[p][0] = (c*a)%MOD, tree[p][1] = (c*b + d)%MOD;
    }
    return;
}

ll find_function_sum(ll l, ll r, ll x){
    // it starts from r-1
    l += (K), r += (K)-1;
    // for merging left child r's
    ll a = 1, b = 0;
    while (l<=r){
        if (l%2 == 1){
            // this would be the inner most function, so x can be updated directly
            x = ((tree[l][0]*x)%MOD + tree[l][1])%MOD;
            l += 1;
        }
        if (r%2 == 0){
            // outer most function, x cannot be directly updated;
            // we update the dummy function instead and apply to x afterwards
            // suppose f(ans)(x) = ax+b
            // then f(ans)(x) would be updated to f(ans)(x) = a(fr(x)) + b
            ll na = (a*tree[r][0])%MOD;
            ll nb = ((a*tree[r][1])%MOD + b)%MOD;
            a = na, b = nb;
            r -= 1;
        }
        l /= 2, r /= 2;
    }
    // apply dummy function
    return ((a*x)%MOD + b)%MOD;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    while (K<N) K <<= 1;
    tree.resize(2*K,{1,0});
    for (int i=0;i<N;i++) cin >> tree[i+K][0] >> tree[i+K][1];
    compute_tree(1);
    // queries
    for (int i=0;i<Q;i++){
        int t; cin >> t;
        if (t == 1){
            // calculate function sum(? not sure what the proper term is)
            ll a,b,c; cin >> a >> b >> c;
            cout << find_function_sum(a,b,c) << '\n';
        }
        else{
            ll a,b,c; cin >> a >> b >> c;
            update_tree(a,b,c);
        }
    }
    return 0;
}