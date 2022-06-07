/*

interesting longest route dp
for bessie to have a net gain after travelling t days, the equation:

    mi * t >= c*t*t

must be true
so even if bessie can gain 1000 each day (max) and c = 1 (min),

    1000 * t >= t * t    =>    1000 >= t

it means that bessie can travel for at most  1000 days. Past that, bessie will only lose money
this then turns into the standard:

    dp[i][j] = maximum gained if bessie stops at city j on the ith day
    (withpout deduction, since it's equal for all citie on the same day)

there is possibility for space optimization, but im lazy and it should pass with O(N^2) space anyways

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M, C;
int dp[maxN][maxN], w[maxN];
vector<int> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("time");

    cin >> N >> M >> C;
    for (int i=1;i<N+1;i++) cin >> w[i];
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        // reversed because we are doing pull dp
        g[b].push_back(a);
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][1] = 0;
    for (int i=1;i<maxN;i++){
        for (int j=1;j<N+1;j++){
            // can she visited the same city consectivly?
            int v = -INF;
            for (int a:g[j]) v = max(v, dp[i-1][a]);
            dp[i][j] = max(dp[i][j], v+w[j]);
        }
    }
    int res = -INF;
    for (int i=1;i<maxN;i++) res = max(res, dp[i][1]-i*i*C);
    cout << res << '\n';
    return 0;
}