/*

essentially maximum array sum but the array has to be of length of a multiple of K
in which case we can simply sum all the possible groups of K together into new arrays and 
compute the maximum array sum of those instead

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N, K;
ll pre[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> K;
    // all are 1-indexed for sanity's sake
    for (int i=1;i<N+1;i++) cin >> pre[i], pre[i] += pre[i-1];

    ll ans = 0;
    vector<ll> arr;
    for (int s=1;s<=K;s++){
        // compute new array starting at position s
        arr.clear();
        for (int k=s;k+K-1<=N;k+=K) arr.push_back(pre[k+K-1]-pre[k-1]);
        ll msf = -1e18, sum = 0;
        // compute maximum array sum for this array
        for (int i=0;i<arr.size();i++){
            if (sum + arr[i] < arr[i]) sum = 0;
            sum += arr[i];
            msf = max(msf, sum);
        }
        ans = max(ans, msf);
    }
    cout << ans << '\n';
    return 0;
}