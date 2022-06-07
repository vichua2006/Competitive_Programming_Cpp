/*

we have to consider two states: whether bessie has drunk the water or not
hence, we two dp

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,A,B;
bool dp[maxN][2];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("feast");

    cin >> N >> A >> B;
    dp[0][0] = 1, dp[0][1] = 1;
    for (int i=1;i<N+1;i++){
        if (i>=A) dp[i][0] |= dp[i-A][0];
        if (i>=B) dp[i][0] |= dp[i-B][0];
        // if bessie drinks water at this moment, she would obtain i/2
        dp[i/2][1] |= dp[i][0];
    }
    for (int i=1;i<N+1;i++){
        if (i>=A) dp[i][1] |= dp[i-A][1];
        if (i>=B) dp[i][1] |= dp[i-B][1];
    }
    for (int i=N;i>0;i--){
        if (dp[i][1]||dp[i][0]){
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}