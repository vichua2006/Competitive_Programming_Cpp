//uses 2D prefix sum array, but how does that work?
/*
for a 1D line, picture buckets being placed at the start of each 
painted interval. then, sweep across the line, and when you arrive at the
beginning of an interval, pick up the bucket, when you arrive at the end, drop the bucket
for any cell, the amount of paint on that cell equals to the number of buckets 
you were carrying when you were on that cell
now expand this to 2 dimensions (it is almost as if a more specific version of DP)
Source: http://www.usaco.org/current/data/sol_paintbarn_silver_feb19.html
*/

#include <iostream>
using namespace std;

int dp[1001][1001];

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
    int n,k,a,b,c,d; cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> a >> b >> c >> d;
        //             -placing the "buckets"
        //              values are picked so that they cancel out if cell is not in area
        dp[a][b] += 1;
        dp[a][d] -= 1;
        dp[c][b] -= 1;
        dp[c][d] += 1;
    }
    int ret = 0;
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            if(i) dp[i][j] += dp[i-1][j];
            if(j) dp[i][j] += dp[i][j-1];
            if(i && j) dp[i][j] -= dp[i-1][j-1];
            if(dp[i][j] == k) ret++;
        }
    }
    // why does this part have to be written this way?
    // damnit, because the x,y can also begin at 0, not 1
    cout << ret << '\n';
    return 0;
}