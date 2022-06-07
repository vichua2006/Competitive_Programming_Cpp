/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,Q,K=1;
vector<int> tree;

int qry(int a,int b){
    a += (K-1),b += (K-1);
    int res = INF;
    while (a<=b){
        if (a%2==1) res = min(res,tree[a++]);
        if (b%2==0) res = min(res,tree[b--]);
        a/=2,b/=2;
    }
    return res;
}

void upd(int p,int v){
    p += (K-1);
    tree[p] = v;
    for (p/=2;p>=1;p/=2) tree[p] = min(tree[2*p],tree[2*p+1]);
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    while (K<N) K *= 2;
    tree.resize(2*K,0);
    for (int i=0;i<N;i++) cin >> tree[i+K];
    for (int i=K-1;i>=1;i--) tree[i] = min(tree[2*i],tree[2*i+1]);
    for (int i=0;i<Q;i++){
        int a,b,c; cin >> a >> b >> c;
        if (a-1){
            cout << qry(b,c) << '\n';
        } else{
            upd(b,c);
        }
    }
    return 0;
}