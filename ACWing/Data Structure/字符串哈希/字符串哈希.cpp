/*

### long comment ###

by using a rolling hash, we can compute the hashes of two substrings in O(1) and compare them in O(1) time

the hash value of a string can be thought of as a number in base-P, where P is a large prime:
hash("abcd") = 1*P^3 + 2*P^2 + 3*P^1 + 4*P^0 (mod K) 

first, we compute all the hashes of the prefixes of the string s

then, similar to using a prefix sum array, we compute the hash of any substring [l, r]:

hash_val = h[r] - h[l - 1]^(r - l + 1) (mod K)

here, K can be conveniently defined as 2^64, due to the (defined) overflow behavior of unsigned long long in c++:
"A computation involving unsigned operands can never overﬂow, because a result that cannot be represented by 
the resulting unsigned integer type is reduced modulo the number that is one greater than the largest value that can be represented by the resulting type."

so by storing the hash values as ulls, c++ basically mods it for us.

(using any number close to a power of 2 as the mod 
is not a good idea in actual practice, however, this is competitive programming)

according to https://preshing.com/20110504/hash-collision-probabilities/
the chances of collison with this particular problem is around 5.5e-7, so there's no need for double hashing

and ACWing recommends P = 131 or 13331
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M, P = 131;
char str[maxN];
// hs is hash value, p is for computing hash later. p[i] = P^i 
ull hs[maxN], p[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> str + 1;
    p[0] = 1;
    for (int i=1;i<N+1;i++){
        hs[i] = str[i] + hs[i-1] * P;
        p[i] = p[i - 1] * P;
    }
    for (int i=0;i<M;i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        ull h1 = hs[b] - hs[a - 1] * p[b - a + 1], h2 = hs[d] - hs[c - 1] * p[d - c + 1];
        if (h1 == h2) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}