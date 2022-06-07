#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,Q,k=1;
vector<int> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int qry(int x){
    int r = 1;
    if (tree[1] < x) return 0;
    while (r<k){
        if (tree[2*r] >= x) r = 2*r;
        else r = 2*r + 1;
    }
    return r-k+1;
}

void upd(int p,int v){
    p += (k-1);
    tree[p] -= v;
    for (p/=2;p>=1;p/=2) tree[p] = max(tree[2*p],tree[2*p+1]);
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    while(k<N) k *= 2;
    tree.resize(2*k,0);
    for (int i=0;i<N;i++) cin >> tree[k+i];
    // compute tree
    for (int i=k-1;i>=1;i--) tree[i] = max(tree[2*i],tree[2*i+1]);

    for (int i=0;i<Q;i++){
        int a; cin >> a;
        int idx = qry(a);
        cout << idx << (i==Q-1?'\n':' ');
        if (idx){
            upd(idx,a);
        }
    }
    return 0;
}