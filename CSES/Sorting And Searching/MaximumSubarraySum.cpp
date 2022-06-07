// okay, this was quite confusing
// I went straight to william lin's CSES speedrun, which taught me nothing
// because I had no clue what Kadane's algorithm is
// basically, a dp. dp[i] denotes the maximum sum of a contiguous subarray that ends at i
// with this, the equation is dp[i] = max(dp[i-1]+new_value,new_value)
// two options: either continue the previous subarray, or start a new one
// its correctness, although not intuitively understood (at least by me),
// can be proven by contradiction
// and the final answer would be max(dp[i]) for 1<=i<=N, since that would include all the subarrays
// O(n) time, and potentially O(1) space, since there's really no need to keep tract of everything
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,ans = -1e18,msf = -1e18;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++){
        ll a; cin >> a;
        //dp[i] = max(dp[i-1]+a,a)
        msf = max(msf+a,a);
        //max(dp[i]) for 1<=i<=N
        ans = max(msf,ans);
    }
    cout << ans;
}