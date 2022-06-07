// simple math
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (ll  k=1;k<N+1;k++){
        ll ans = (k*k)*((k*k)-1)/2 - (k-3+1)*(k-2+1)*4;
        cout << ans << '\n';
    }
    return 0;
}