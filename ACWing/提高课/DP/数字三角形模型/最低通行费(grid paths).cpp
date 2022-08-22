/*

another standard grid paths, but the topic is slightly, and I mean slightly hidden

notice that the salesman must leave with 2N - 1 units of time, which is basically just saying the he can only go
down or right, because any other move will result in a time that is longer than 2N - 1;

don't forget to initialize

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
// and I just realized that this can be optimized to 1-d
int dp[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<N+1;j++){
            int a; cin >> a;
            dp[j] = a + min(dp[j], dp[j - 1]);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}