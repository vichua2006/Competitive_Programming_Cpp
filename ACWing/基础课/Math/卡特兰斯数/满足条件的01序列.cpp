/*

each arrangement corrisponds to a path on a grid from (1, 1) to (n, n)

there are thus C(2n, n) solutions

however, the problem's contrain is that there must be at least as many 0s as there are 1s in any prefix
this constrain can translated to the grid model: the path can never go past line A, or
it can never touch line B

paths that never touch line B = total paths - lines that do touch line B

and for any path that passes line B, we can find the first point at which it contacts line B, 
reflected in across the line (it can pass line B again at a later time), and end up path from (1, 1) to (n - 1, n + 1).
Similarly, any such paths can be reflected across the line y = x + 1 to a paths taht ends
at (n, n)

Hence, any paths from (1, 1) to (n, n) that CONTACTS line B corrisponds to a path
from (1, 1) to (n - 1, n + 1). And there are C(2n, n - 1) = C(2n, n + 1) such paths

thus, the answer equals C(2n, n) - C(2n, n - 1) for any n, and by the second image, 
it is the nth catalan number, which is a common solution to many counting problems
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N;


void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll ep(ll a, ll k, ll p){
    ll res = 1;
    while (k){
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k /= 2;
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    ll res = 1;
    for (int i=2*N;i>N;i--) res = res * (ll)i % MOD;
    for (int i=1;i<N+1;i++) res = res * ep((ll)i, MOD - 2, MOD) % MOD;

    res = res * ep(N + 1, MOD - 2, MOD) % MOD;
    cout << res << '\n';

    return 0;
}