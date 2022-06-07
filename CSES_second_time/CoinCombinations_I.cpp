#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 1,maxM = 1e6+1,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,X,dp[maxM],c[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> X;
    for (int i=1;i<N+1;i++) cin >> c[i];
    dp[0] = 1;
    for (int i=1;i<X+1;i++){
        for (int j=1;j<N+1;j++){
            if (i>=c[j]) dp[i] = (dp[i]+dp[i-c[j]])%MOD;
        }
    }
    cout << dp[X] << '\n';
    return 0;
}