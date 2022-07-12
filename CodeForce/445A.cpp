/*

so this is actually a dp problem: https://codeforces.com/problemset/problem/455/A
editorial: https://codeforces.com/blog/entry/13336

let dp[i] denote the max number of points we can obtain by considering the first i numbers (1, 2, 3,..., i)
therefore,

    dp[i] = max(dp[i-1], dp[i-2] + cnt[i]*i), where cnt[i] denotes how many number i are in the array arr
    (we either pick i-1, which discards i, or we pick i, which discards i-1 but gains cnt[i]*i points)

the answer would equal dp[max(arr[0], arr[1],..., arr[N-1])]

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
ll cnt[maxN], dp[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
 
    cin >> N;
    int mx = 0;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        cnt[a] += 1;
        mx = max(mx, a);
    }
    dp[0] = 0;
    dp[1] = cnt[1];
    for (int i=2;i<=mx;i++){
        dp[i] = max(dp[i-1], dp[i-2] + cnt[i]*i);
    }
    cout << dp[mx] << '\n';
    return 0;
}