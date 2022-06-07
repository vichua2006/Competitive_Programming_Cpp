/*

suppose a is highest value in A, and c is the highest value in B
let b in A, b != a and a >= b. d in B, d != c, c >= d

we can prove that it is always better to pair up ac and bd instead of ad and bc

let ac + bd = k

then, ad + bc = k - ac + ad - bd + bc = k + a(d-c) + b(c-d) = k + (b-a)(c-d) = K - (a-b)(c-d)

since a >= b and c >= d, (a-b)(c-d) >= 0.

therefore ad + bc <= ac + bd

so the two largest must be paired together. after there paired, new "largest" appears and the process repeats until all are paired

as for the increasing points thing, it's always best to give them to the largest pair and make that pair a perfect square (make it so that a = b)
if there is still points leftover, just split the rest between the two.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,K;
ll A[maxN], B[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> K;
    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<N;i++) cin >> B[i];
    sort(A,A+N),sort(B,B+N);
    // val = points to make a = b
    ll val = min((ll) K,abs(A[N-1]-B[N-1]));
    K -= val;
    if (A[N-1] > B[N-1]) B[N-1] += val;
    else A[N-1] += val;
    // split remaining K
    A[N-1] += K/2, B[N-1] += K/2 + K%2;
    ll res = 0;
    for (int i=0;i<N;i++) res = (res + (A[i]*B[i])%MOD)%MOD;
    cout << res << '\n';
    return 0;
}