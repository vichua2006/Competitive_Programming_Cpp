#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,K=1;
vector<ll> tree; 

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll qry(ll a,ll b){
    a += (K-1),b += (K-1);
    ll res = 0;
    while(a<=b){
        if (a%2==1) res += tree[a++];
        if (b%2==0) res += tree[b--];
        a /= 2,b /= 2;
    }
    return res;
}

void upd(ll p,ll v){
    p += (K-1);
    tree[p] = v;
    for (p/=2;p>=1;p/=2) tree[p] = tree[2*p]+tree[2*p+1];
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    while(K<N) K *= 2;
    tree.resize(2*K,0);
    for (int i=0;i<N;i++) cin >> tree[i+K];
    for (int i=K-1;i>=1;i--) tree[i] = tree[2*i]+tree[2*i+1];
    for (int i=0;i<M;i++){
        ll a,b,c; cin >> a >> b >> c;
        if (a-1){
            cout << qry(b,c) << '\n';
        }
        else{
            upd(b,c);
        }
    }
    return 0;
}