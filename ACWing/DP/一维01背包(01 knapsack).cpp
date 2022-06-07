// the standard problem can appearently be done with one dimentional dp?
// reasoning was that since the equation dp[i][j] = max(dp[i-1][j],(j-v[i]>=0?dp[i-1][j-v[i]]+w[i]:0));
// only uses dp[i-1] for dp[i], we can fit all of it in single array
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN],w[maxN],v[maxN];
// dp[i] = max value achieved with i space

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> v[i] >> w[i];
    // in actual sense, we are still calculating in the form dp[i][j]
    // but we are just overwriting the same array N times
    for (int i=1;i<N+1;i++){
        //we are calculating in reverse because that way, we can correctly access dp[i-1]
        // to make sure that we are using dp[i-1][j] and not dp[i][j]
        for (int j=M;j>=v[i];j--){
            // here, dp[j] is equivalent of d[i-1][j]
            // dp[j-v[i]]+w[i] is dp[i-1][j-v[i]]+w[i]
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout << dp[M] << '\n';
    return 0;
}