#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 25e1 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,K,dp[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> K;
    // j is pie, i is people
    for (int i=1;i<K+1;i++){
        for (int j=1;j<N+1;j++){
            if (j<i) continue;
            if (i==j||i==1) dp[i][j] = 1;
            // the ith person has two options: take 1 pie and leave, or take one pie and keep going
            // in the first case, we just left with how to give j-1 pies to i-1 people
            // in the second case, since i took 1, then everyone after i also needs to take at least 1
            // which, if everyone is going to get 1 by default, we are left with how to give j-i pies to i people
            else dp[i][j] += dp[i-1][j-1] + dp[i][j-i];
        }
    }
    cout << dp[K][N] << '\n';
    return 0;
}