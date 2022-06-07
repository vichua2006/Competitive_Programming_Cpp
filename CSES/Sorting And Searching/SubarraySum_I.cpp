/*

IMPORTANT: subarray and substrings ARE continuous. Subsequence is the non-continuous one.
using a map, for every pre[i], we check how many pre[i] - x there are
then we update the map with the new pre[i]

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,M;
unordered_map<ll,ll> d;

void setIO(string name){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO("hps");

    cin >> N >> M;
    d[0] = 1;
    ll sum = 0,cnt = 0;
    for (int i=0;i<N;i++){
        ll a; cin >> a;
        sum += a;
        cnt += d[sum-M];
        d[sum] += 1;
    }
    cout << cnt << '\n';
    return 0;
}