/*

for these types of problems, observations are always key

first, realize that, for any currency system (n, a), if there exists a a[x] such that it can be expressed with 
other a[i] * t[i], then it can be erased without affecting the number of amounts it can express

next, for any (m, b) equivalent to (n, a), all of a[1], a[2], ... , a[n] must be expressible by b[1], b[2], ... , b[m]

and by manually solving for the sample cases, we can notice that the the currencies in the optimal solution (m, b)
seems only contain currencies from (n, a). In other words, (m, b) appears to be subset of (n, a)

thus, we can guess and try to prove that this is generally true:
(by contradiction)

    suppose (n, a) has a equivalent system (m, b) with the smallest m

    let u be an element in (m, b) that is NOT in (n, a)

    because (n, a) is completely equivalent to (m, b), it means that u must be expressible by (n, a)

    since u itself is not a part of (n, a), multiple a[i]s must be used

    therefore, u = a[1] * t[1] + a[2] * t[2] + ... + a[n] * t[n]
    for some t[i] >= 0

    notice that, since a[i] and t[i] are non-negative, for any i where t[i] is positive, a[i] must be less than u (a[i] < u)

    and since both systems are equivalent, each a[i] used in the above expression can be again expressed with b[1] * si[1] + ... + b[m] * si[m]

    therefore, the above expression can be rewritten as (substitude every a[i]):

        u = (b[1] * s1[1] + ... + b[m] * s1[m]) * t[1] + (b[1] * s2[1] + ... + b[m] * s2[m]) * t[2] + ... + (b[1] * sn[1] + ... + b[m] * sn[m]) * t[n]

    and since each a[i] is less than u, each of the b[i] that was actually used is also less than u 
    (in other words, u is not used to express itself)

    now, this equation shows that u can expressed by other b[i], and by our first observation, 
    it means that u is not necessary, and can be erased without any affect.

    this means that m can be reduced to m - 1 by erasing u, which contradicts the first statement of this proof

    thus, u must be IN (n, a)

thus, we get that the optimal (m, b) is a subset of (n, a), which is convienent as it guarentees that 
if x cannot be expressed by (n, a), then it cannot be expressed by subset of it

and we simply need to find the minimum number of elements to pick

and finally, our final observation is that the smallest element of (n, a) must be pick
thus, we can use a greedy approach

we sort all elements of (n, a) from smallest to largest and iterate them in that order

for each element e, there are two possibilities

1. e can already be expressed by previous chosen elements, or
2. e cannot be expressed by previously chosen elements, and because there is not a smaller element that may
be able to express e, it must picked

notice that since n <= 100 and a[i] <= 25000, we can maintain dp array where 
dp[i] denotes if i can be expressed by currently picked numbers

we simple count the times we must pick an element, and that is our answer

time complexity: O(T * N * max(a[i])) ~ 5e7, pretty close to the limit

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2.5e4 + 10, INF = 1e9, MOD = 1e9 + 7;
int T, N;
int arr[maxN];
bool dp[maxN];  

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T -- ){
        cin >> N;

        for (int i=0;i<N;i++) cin >> arr[i];
        sort(arr, arr + N);

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int cnt = 0;

        for (int i=0;i<N;i++){
            if (dp[arr[i]]) continue;
            cnt ++ ;
            
            for (int j=arr[i];j<maxN;j++) dp[j] |= dp[j - arr[i]];
        }
        cout << cnt << '\n';
    }

    return 0;
}