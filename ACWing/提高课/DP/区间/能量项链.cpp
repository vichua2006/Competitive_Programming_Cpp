/*

same logic as the previous one, but the individual rocks and computing method are a bit different

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN];
int dp[maxN][maxN];
ar<int, 2> obj[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> arr[i];
    for (int i=N+1;i<=2*N;i++) arr[i] = arr[i - N];
    // create each object
    for (int i=1;i<2*N;i++) obj[i][0] = arr[i], obj[i][1] = arr[i + 1];

    for (int i=1;i<2*N;i++){
        for (int j=i;j;j--){
            for (int k=j;k<i;k++){
                dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + obj[j][0] * obj[k][1] * obj[i][1]);
            }
        }
    }

    int res = 0;
    for (int i=1;i<2*N;i++) res = max(res, dp[i][i + N - 1]);

    cout << res << '\n';

    return 0;
}