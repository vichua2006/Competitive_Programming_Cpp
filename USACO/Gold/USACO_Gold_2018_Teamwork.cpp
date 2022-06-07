/*

dp[i] = highest possible=sum acheived with the first i cows with 
cow i being the last member of the last team

therefore,

    dp[i] = max(max(w[i]...w[i]) + dp[i-1], max(w[i]...w[i-1]) + dp[i-2], ... , max(w[i]...w[i-k+1]) + dp[i-k])

the naive version of the this solution requires O(NK^2) time, but the max(w[i]...w[j]) can 
be simply maintained for each i, without having to loop through the array

final time: O(NK)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, K;
int dp[maxN], w[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("teamwork");

    cin >> N >> K;
    for (int i=1;i<N+1;i++) cin >> w[i];
    for (int i=1;i<N+1;i++){
        int msf = w[i];
        for (int j=1;j<K+1&&i-j>=0;j++){
            // include j cows on this team
            msf = max(msf, w[i-j+1]);
            dp[i] = max(dp[i], dp[i-j] + j*msf);
        }
    }
    cout << dp[N] << '\n';
    return 0;
}