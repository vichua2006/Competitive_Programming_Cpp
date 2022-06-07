//dp[i][j] = max using elements from first i groups, j space
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN],v[maxN][maxN],w[maxN][maxN],s[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        cin >> s[i];
        for (int k=1;k<s[i]+1;k++) cin >> v[i][k] >> w[i][k];
    }    
    for (int i=1;i<N+1;i++){
        for (int j=M;j>0;j--){
            for (int k=1;k<s[i]+1;k++){
                if (j>=v[i][k]) dp[j] = max(dp[j],dp[j-v[i][k]]+w[i][k]);
            }
        }
    }
    cout << dp[M] << '\n';
    return 0;
}