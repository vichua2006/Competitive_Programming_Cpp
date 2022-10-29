/*

a variation of standard LIS

instead of dp[i] denoting the length of the increasing subsequence that ends on i, it now denotes the max sum of said sequence

since they want the largest sum, the answer should equal to the max(dp[i]) for all i

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int dp[maxN], arr[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> arr[i];

    int msf = 0;
    for (int i=1;i<N+1;i++){
        dp[i] = arr[i];
        for (int j=1;j<i;j++){
            if (arr[j] < arr[i]) dp[i] = max(dp[i], arr[i] + dp[j]);
        }

        msf = max(msf, dp[i]);
    }

    cout << msf << '\n';

    return 0;
}