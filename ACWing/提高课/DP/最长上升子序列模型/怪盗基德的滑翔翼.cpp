/*

an pretty simple variation of the longest increasing subsequence
and since the data is small, even the unoptimized version should pass

for each test case, we just need to dp twice, since the problem states that it can go in either direction

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int T, N;
int arr[maxN], dp[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int solve(){
    memset(dp, 0, sizeof(dp));
    int msf = 0;
    for (int i=1;i<N+1;i++){
        // dp[0] = 0 by definition
        for (int j=0;j<i;j++){
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }

        msf = max(msf, dp[i]);
    }

    return msf;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T -- ){
        cin >> N;
        for (int i=1;i<N+1;i++) cin >> arr[i];
        int ans = 0;
        ans = max(ans, solve());
        reverse(arr + 1, arr + N + 1);
        ans = max(ans, solve());
        cout << ans << '\n';
    }

    return 0;
}