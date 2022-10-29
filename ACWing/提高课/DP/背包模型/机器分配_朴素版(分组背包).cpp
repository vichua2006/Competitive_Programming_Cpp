/*

(分组背包)

let dp[i][j] denote the maximum possible value achieved by considering only the first i companies and
using no more than m computers

dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + arr[i][1], ... , dp[i - 1][0] + arr[i][M])

each arr[i][j] values can be seen as an object belonging to the ith group with value of arr[i][j] and a size of j

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e1 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int dp[maxN], arr[maxN][maxN];
vector<int> rec[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) for (int j=1;j<M+1;j++) cin >> arr[i][j];

    for (int i=1;i<N+1;i++){
        for (int j=M;j>=0;j--){
            int cnt = 0;
            for (int k=1;k<j+1;k++){
                if (dp[j - k] + arr[i][k] > dp[j]){
                    dp[j] = dp[j - k] + arr[i][k];
                    cnt = k;
                }
            }
            rec[j] = rec[j - cnt];
            rec[j].push_back(cnt);
        }
    }

    cout << dp[M] << '\n';

    for (int i=0;i<N;i++) cout << i + 1 << ' ' << rec[M][i] << '\n';

    return 0;
}