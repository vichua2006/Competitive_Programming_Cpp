/*

a, b <= 1e5 this time, so precomputing all of C(b, a) would not be possible
however, we can still precompute the factorial of all i <= 1e5

I first didn't think about this because it would involve modular division, but then realized that 1e9 + 7 is prime,
which means that all of it's modular inverses exists

so we just need to compute f[i] = i! and inf[i] = (i!)^-1

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M = 1e5;
ll f[maxN], inf[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll ep(ll a, ll b, ll p){
    ll res = 1;
    while (b){
        if (b&1){
            res = (res * a) % p;
            b -= 1;
        }
        a = (a * a) % p;
        b /= 2;
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    f[0] = 1, inf[1] = 1;
    for (int i=1;i<M+1;i++) f[i] = (i * f[i - 1]) % MOD;
    for (int i=2;i<M+1;i++) inf[i] = ep(f[i], MOD - 2, MOD) % MOD; 

    cin >> N;

    for (int i=0;i<N;i++){
        int a, b; cin >> a >> b;
        // C(b, a) = a! / (b! * (a - b)!)
        if (a == b) cout << 1 << '\n';
        else cout << (((f[a] * inf[b]) % MOD) * inf[a - b]) % MOD << '\n';
    }
    return 0;
}