/*
 
see the analysis markdown file in the same folder
 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array
 
const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N;
 
ll ep(ll a, ll k, ll p){
    ll res = 1;
    while (k){
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k /= 2;
    }
 
    return res;
}

ll sm(ll s, ll e){
    return(
        ((s + e) % MOD) * ((e - s + 1) % MOD) % MOD
    );
}
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
 
    cin >> N;
    // find the modular inverse via fermat's little theorem
    ll ans = 0, inv2 = ep(2, MOD - 2, MOD);
    // while greater than 0
    for (ll k = N; k;){
        ll j = N / k;
        ll kx = N / j, ky = N / (j + 1);
        ans = (ans + (j * sm(ky + 1, kx) % MOD) * inv2 % MOD) % MOD;
        k = ky;
    }
    cout << ans << '\n';
 
    return 0;
}