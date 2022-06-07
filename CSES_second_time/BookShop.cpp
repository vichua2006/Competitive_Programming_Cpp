#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 1e5+1;
int N,X,dp[maxN],w[maxN],v[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X;
    for (int i=1;i<N+1;i++) cin >> v[i];
    for (int i=1;i<N+1;i++) cin >> w[i];
    for (int i=1;i<N+1;i++){
        for (int j=X;j>=v[i];j--){
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout << dp[X] << '\n';
    return 0;
}