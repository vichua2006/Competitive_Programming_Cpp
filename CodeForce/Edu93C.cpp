/*

sum (al+a(l+1)+...+ar) = r-l+1 -> pre[r] - pre[l-1] = r-l+1
-> pre[r] - r = pre[l-1] - l+1

let k = l-1;

-> pre[r] - r = pre[k] - k (1)

so, for any r,k such that (1) is true, [k,r] (or [r,k], ording doesn't really matter as long as you
count them right) is a "good subarray"

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int T,N;
unordered_map<ll,ll> d;
char num[maxN];

void setIO(string name){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO("maxcross");

    cin >> T;
    while (T--){
        cin >> N;
        d.clear();
        ll cnt = 0, sum = 0;
        cin >> num+1;
        // since x may end up as a negative number, a map is better
        // d[0] = 1 is for situations where r==l, so that the fits one gets counted right
        d[0] = 1;
        for (int i=1;i<N+1;i++){
            sum += (ll) num[i]-'0';
            ll x = sum-i;
            cnt += d[x]++;
        }
        cout << cnt << '\n';
    }
    return 0;
}