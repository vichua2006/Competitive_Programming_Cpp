/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    ll ans = -INF,msf = -INF;
    for (int i=0;i<N;i++){
        ll a; cin >> a;
        msf = max(a,msf+a);
        ans = max(ans,msf);
    }
    cout << ans << '\n';
    return 0;
}