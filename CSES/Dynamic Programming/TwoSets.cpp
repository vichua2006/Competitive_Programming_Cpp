// knapsack, actually. 
// since we have to divid the numbers 1,2..n into equal sum, it means that each
// set will sum to half of the total sum, (n+1)n/2, which is (n+1)n/4
// so, we have to calculate in how many ways we can obtain (n+1)n/4
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e2 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,dp[maxN][(maxN+1)*maxN/4 + 1];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    // if the total sum is even, it's impossible
    if ((N+1)*N/2&1){
        cout << 0 << '\n';
        return 0;
    }
    //dp[i][x] = number of ways x can be made using the first i weights
    dp[0][0] = 1;
    for (int i=1;i<N+1;i++){
        for (int j=0;j<=(N+1)*N/4;j++){
            dp[i][j] = (dp[i-1][j]+(j-i>=0?dp[i-1][j-i]:0))%MOD;
        }
    }
    // by only considering the sets that do not include N, we count exactly half of the total number of valid sets
    // (more specifically, we count only one set from every pair of solutions, since N must be in one of them)
    // since N is not in this set, it must be in the other set pair. E.g., {3,4,7} and {1,2,5,6}. we would only count the latter in this case
    cout << (dp[N-1][(N+1)*N/4]) << '\n';
    return 0;
}