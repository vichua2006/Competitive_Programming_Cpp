// another classic dp problem

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int maxN = 1e6+1;

int n,x,dp[maxN];
vector<int> coins;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> x;
    memset(dp,0x3f,sizeof dp);
    for (int i=0;i<n;i++){
        int a ;cin >> a;
        coins.push_back(a);
        dp[a] = 1;
    }
    for (int i=1;i<x+1;i++){
        for (int a: coins){
            dp[i] = min(dp[i],dp[max(0,i-a)]+1);
        }
    }
    cout << (dp[x] > 1e9 ? -1:dp[x]) << '\n';
    return 0;
}