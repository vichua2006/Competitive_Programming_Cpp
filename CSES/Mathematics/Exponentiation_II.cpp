#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll Mod = 1e9+7;
ll n,a,b,c;

ll solve(ll a, ll b, ll m){
    ll r = 1;
    while (b){
        if (b&1) r = r*a%m;
        a = a*a%m;
        b /= 2;
    }
    return r;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a >> b >> c;
        // fermat's little theorem: if gcd(a,p) = 1, then a^(p-1) = 1 (mod p)
        // so, we let b^c = q(p-1) + r, q,r in Z
        // therefore a^(b^c) = a^(q(p-1) + r) = a^(q(p-1)) * a^r
        // by fermat's little theorem, (a^q)^(p-1)) * a^r = 1 * a^r (mod p)
        // therefore a^(b^c) = a^r (mod p),
        // where b^c = r (mod p-1), since b^c = q(p-1) + r
        cout << solve(a,solve(b,c,Mod-1),Mod) << '\n';
    }
    return 0;
}

