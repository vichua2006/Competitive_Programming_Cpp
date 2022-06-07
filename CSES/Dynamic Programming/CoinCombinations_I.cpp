// classic

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1e6 + 1, MOD = 1e9 + 7;

int n,x,dp[maxN];
vector<int> coins;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> x;
    for (int i=0;i<n;i++){
        int a; cin >> a;
        coins.push_back(a);
        dp[a] = 1;
    }
    for (int i=1;i<x+1;i++){
        for (int a:coins) dp[i] = (dp[i] + dp[max(0,i-a)])%MOD;
    }
    cout << dp[x];
    return 0;
}