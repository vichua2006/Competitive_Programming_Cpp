#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,M,K=1;
vector<ll> tree; 

ll qry(int a,int b){
    a += (K-1),b += (K-1);
    ll res = 0;
    while (a<=b){
        if (a%2==1) res ^= tree[a++];
        if (b%2==0) res ^= tree[b--];
        a/=2,b/=2;
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    while (K<N) K *= 2;
    tree.resize(2*K,0);
    for (int i=0;i<N;i++) cin >> tree[i+K];
    for (int i=K-1;i>=1;i--) tree[i] = tree[2*i]^tree[2*i+1];
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        cout << qry(a,b) << '\n';
    }
    return 0;
}