#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll Mod = 1e9 + 7;

ll n,a,b;

ll pM(ll a, ll b, ll m){
    ll r = 1;
    // instead of increasing by 1 each time, turn a^b (mod m) into (a^2)^b/2 (mod m) which allows log n time
    while (b != 0){
        // if b is odd, we cannot directly divide by 2, therefore we take out 1 b and make it even
        if (b&1){
            r = r*a%m;
            b -= 1;
        }
        // a (mod m) == a^n (mod m), so a^b (mod m) == (a^2 (mod m) )^b/2 (mod m)
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
        cin >> a >> b;
        cout << pM(a,b,Mod) << '\n';
    }
    return 0;
}