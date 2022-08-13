/*

by fermat's little theorem, if (a, p) = 1, then a^(p - 1) = 1 (mod p)

a^(p - 1) = a * a^(p - 2) = 1
which means that a^(p - 2) is the modular inverse of a

so we really only need to find a^(p - 2)

and proving fermat's theorem again as review
see proof in the same file

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll f(ll a, ll b, ll p){
    int res = 1;
    while (b > 0){
        if (b&1){
            res = (res * a) % p;
            b -= 1;
        } else {
            a = (a * a) % p;
            b /= 2;
        }
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    while (N -- ){
        ll a, p; cin >> a >> p;
        if (a % p == 0) cout << "impossible\n";
        else cout << f(a, p - 2, p) << '\n';
    }

    return 0;
}