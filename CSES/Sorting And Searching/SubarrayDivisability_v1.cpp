/*
 
cnt[k] denotes number of prefix sums such that pre[i] = k (mod N)
for every 0 <= k < N

then, for every pre[i], pre[j] of the same residue class, pre[j] - pre[i] will yield a subarray [i + 1, j] 
whose sum is a multiple of N. for each k, there are cnt[k] * (cnt[k] - 1) / 2 such pairs of (i, j)

thus, the answer is the sum of cnt[k] * (cnt[k] - 1) / 2 for all k
 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array
 
const int maxN = 2e5 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int cnt[maxN];
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
 
    cin >> N;
    ll sum = 0;

    // empty array has a sum of 0 (allows the first multiple-of-N array to be counted)
    cnt[0] = 1;
    for (int i=0;i<N;i++){
        ll a; cin >> a;
        sum += a;
        // ensures that the value is positive; -k = n - k (mod n)
        cnt[((sum % N) + N) % N] ++ ;
    }
 
    ll res = 0;
    for (int i=0;i<N;i++) res += (ll) cnt[i] * (cnt[i] - 1) / 2;
    cout << res << '\n';

    return 0; 
}