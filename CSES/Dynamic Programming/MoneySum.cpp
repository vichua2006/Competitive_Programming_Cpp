//appearently called classic 0-1 knapsack
//dp[i][x] = if we can get value x by using the first i coins

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,c[101];
bool dp[101][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> c[i];
    // initialization - you can reach value 0 by using 0 coins
    dp[0][0] = true;
    for (int i=1;i<N+1;i++){
        for (int j=0;j<maxN;j++){
            // check if we can make j-ci with the previous i-1 coins or if we already make j with the previous i-1 coins
            if (j-c[i]>=0) dp[i][j] |= dp[i-1][j-c[i]];
            dp[i][j] |= dp[i-1][j];
        }
    }
    vector<int> ans;
    int cnt = 0;
    for (int i=1;i<maxN;i++){
        if (dp[N][i]){
            cnt += 1;
            ans.push_back(i);
        }
    }
    cout << cnt << '\n';
    for (int i=0;i<ans.size();i++) cout << ans[i] << (i==ans.size()-1?'\n':' ');
    return 0;
}