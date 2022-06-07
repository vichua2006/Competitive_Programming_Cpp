#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,Q,K=1,arr[maxN],dif[maxN];
vector<ll> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll qry(int a,int b){
    a += (K-1),b += (K-1);
    ll res = 0;
    while (a<=b){
        if (a%2==1) res += tree[a++];
        if (b%2==0) res += tree[b--];
        a/=2,b/=2;
    }
    return res;
}

void upd(int p,ll v){
    p += (K-1);
    tree[p] += v;
    for (p/=2;p>=1;p/=2) tree[p] = tree[2*p]+tree[2*p+1];
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=1;i<N+1;i++) cin >> arr[i];
    for (int i=1;i<N+1;i++) dif[i] = arr[i]-arr[i-1];
    while (K<N) K *= 2;
    tree.resize(2*K,0);
    for (int i=1;i<N+1;i++) tree[i+K-1] = dif[i];
    //build tree
    for (int i=K-1;i>=1;i--) tree[i] = tree[2*i]+tree[2*i+1];
    // queries
    for (int i=0;i<Q;i++){
        ll a,b,c,d; cin >> a;
        if (a-1){
            cin >> b;
            cout << qry(1,b) << '\n';
        }
        else{
            cin >> b >> c >> d;
            // dif[b] needs to increase by d, dif[c+1] needs to decrease by d
            upd(b,d);
            if (c+1<=N) upd(c+1,-1*d);
        }
    }
    return 0;
}