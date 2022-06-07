/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,c[maxN];
bool dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> c[i];
    dp[0] = 1;
    for (int i=1;i<N+1;i++){
        for (int j=maxN-1;j>=c[i];j--) dp[j] |= dp[j-c[i]];
    }
    vector<int> ans;
    for (int i=1;i<maxN;i++){
        if (dp[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int a:ans) cout << a << ' ';
    return 0;
}