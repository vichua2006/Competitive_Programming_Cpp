/*

mixed 0-1, bounded and unbounded together

for the bounded items, just use the binary optimization and turn them into 0-1 knapsack, and
for the unbounded, the exact same logic is standard unbounded knapsack applies.

time: O(N * V * log(Smax)) ~ 1000 * 1000 * 10 = 1e7

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    vector<ar<int, 3>> arr;

    for (int i=0;i<N;i++){
        int v, w, s; cin >> v >> w >> s;
        if (s == -1){
            arr.push_back({v, w, 0});
        } else if (s == 0){
            arr.push_back({v, w, 1});
        } else {
            for (int k=1;k<=s;k*=2){
                arr.push_back({k * v, k * w, 0});
                s -= k;
            }
            if (s) arr.push_back({s * v, s * w, 0});
        }
    } 

    for (auto a : arr){
        int v = a[0], w = a[1], t = a[2];
        if (t){
            for (int j=v;j<M+1;j++) dp[j] = max(dp[j], dp[j - v] + w);
        } else {
            for (int j=M;j>=v;j--) dp[j] = max(dp[j], dp[j - v] + w);
        }
    }

    cout << dp[M] << '\n';

    return 0;
}