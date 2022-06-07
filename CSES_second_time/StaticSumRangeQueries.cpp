#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,Q,pre[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=1;i<=N;i++) cin >> pre[i], pre[i] += pre[i-1];
    for (int i=0;i<Q;i++){
        ll a,b; cin >> a >> b;
        cout << pre[b]-pre[a-1] << '\n';
    }
    return 0;
}