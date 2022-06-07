#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 2e5 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
int N,K=1,arr[maxN];
vector<int> tree;

int qry(int a){
    int p = 1;
    while (p<K){
        if (tree[2*p]>=a) p *= 2;
        else a -= tree[2*p],p = 2*p+1;
    }
    return p-K+1;
}

void upd(int p){
    p += (K-1);
    tree[p] -= 1;
    for (p/=2;p>=1;p/=2) tree[p] = tree[2*p]+tree[2*p+1];
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> arr[i];
    while (K<N) K *= 2;
    tree.resize(2*K,0);
    for (int i=0;i<N;i++) tree[i+K] = 1;
    for (int i=K-1;i>=1;i--) tree[i] = tree[2*i]+tree[2*i+1];
    for (int i=0;i<N;i++){
        int a; cin >> a;
        int idx = qry(a);
        cout << arr[idx] << ' ';
        upd(idx);       
    }
    return 0;
}