/*

looking at the number by between indices [i, j] with length d = i - j + 1:

D = s[i] * 10^{d - 1} + s[i + 1] * 10^{d - 2} + ... + s[j - 1] * 10 + s[j]

suppose we are iterating the substring in reverse order.
let S_k denote the suffix of length k

thus, 
S_i = s[i] * 10^{i - 1} + s[i + 1] * 10^{i - 2} + ... + s[1] * 10 + s[0]
and,
S_j = s[j] * 10^{j - 1} + s[j + 1] * 10^{j - 2} + ... + s[1] * 10 + s[0]

(substrings [N - i + 1, N] and [N - j + 1, N] respectively, reversed for more intuitive understanding)

thus, we that 
S_i - S_j = D * 10^{j - 1}

for the problem, we need to check if D = 0 (mod 2019)

since gcd(10, 2019) = 1, then the modular inverse of 10 exists under mod 2019
thus, 
    D = 0 (mod 2019) 
<=> D * 10^{j - 1} = 0 (mod 2019)
<=> S_i - S_j = 0 (mod 2019)
<=> S_i = S_j (mod 2019)

hence, for each i (mod 2019) we count the number of suffixes (or prefixes) that equals i mod 2019

this uses a suffixes, as the prefix version is slightly more annoying to think about

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 2019;
int N;
int arr[maxN], cnt[maxN];
string S;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> S;
    N = S.size();
    for (int i=N-1;i>=0;i--) arr[N - i] = int(S[i] - '0');

    // cnt[0] = 1 since an empty suffix is technically 0,
    // counts the first suffix that is a multiple of 2019
    cnt[0] = 1;
    int num = 0, factor = 1;
    for (int i=1;i<N+1;i++){
        // to compute the answer, we can either compute it while we count, 
        // or count first, then compute
        // this one counts first
        num = num + (arr[i] * factor) % MOD;
        num %= MOD;
        cnt[num] ++ ;
        factor = (factor * 10) % MOD;
    }

    ll ans = 0;
    for (int i=0;i<MOD;i++) ans += (ll)cnt[i] * (cnt[i] - 1) / 2;

    cout << ans << '\n';

    return 0;
}