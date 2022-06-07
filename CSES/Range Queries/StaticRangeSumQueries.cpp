// just a prefix sum array
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,Q,arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=1;i<N+1;i++){
        int a; cin >> a;
        arr[i] = a + arr[i-1];
    }
    for (int i=0;i<Q;i++){
        int a,b; cin >> a >> b;
        cout << arr[b]-arr[a-1] << '\n';
    }
    return 0;
}