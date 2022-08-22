/*

dp[i] represents all increasing subsequences that ends at index i
therefore, dp[i] = max(dp[i-1],dp[i-2]....dp[1]);

However, this will take O(N^2) time, which takes too long for N>1e3~1e4

the following optimization could be made:

take the example 

    7
    3 1 2 1 8 5 6

notice that the longest increasing subsequence that ends on 3 and 1 both have length 1
for any future LIS after 3 and 1, we only need to consider 1, because both are only length 1, and 1 is smaller
(which offers more room to work with)

e.g. take 8. 8 can be placed in a LIS after 3, which means that it can definitely be
placed in a LIS after 1. Vice versa, take 1 in position 4, it can't be placed after 1, so it definitely can't be placed after 3

hence, for all increasing subsequences of length k, we only need to keep tract of
the smallest out of all the numbers that the sequence ends on.

in the example, k = 2. we have 1->2 and 1->8. both are length 2, but one ends on 2, the other 8
in this case, we keep the one that ends with 2

with this, we should using an array of length N: arr[i] = smallest number when k = i, 1<=k<=N
the problem now transforms into finding the largest i with arr[i] <= N

Next notice arr[i] > arr[i-1];

we prove by contradiction:

suppose i > j, arr[i] = arr[j]. let arr[i] = k
this means that there are ISs of length i and i-1 thats end on k as their minimum value
since it is a increasing subsequence, it means that it is strictly increasing for any sequence, s[i] > s[i-1]
since arr[i] = k, we know that there exists a sequence of length i-1 that ends on at most k-1

however, this contradicts with the fact that arr[i-1] = k, whihc is greater than k-1

Now we know that arr is sorted, the operation of finding the largest i with arr[i] <= N can be
done with binary search. this reduces the complexity to O(NlogN), which can handle larger N
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    int ans = 0;
    memset(arr,0x3f,sizeof(arr));
    for (int i=0;i<N;i++){
        int a,p = 0; cin >> a;
        for (int b=N;b>=1;b/=2){
            // must be strictly greater than, not greater or equal to
            // if it is the latter, then we would get the longest non decreasing subsequence instead.
            while (b+p<=N&&a>arr[b+p]) p += b;
        }
        ans = max(ans,p+1);
        arr[p+1] = min(a,arr[p+1]);
    }
    cout << ans << '\n';
    return 0;
}