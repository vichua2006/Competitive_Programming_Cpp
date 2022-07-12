/*

interesting problem

to count k such numbers, you simply first count to k. since there are k/n numbers in up to k that is divisible by n, we actually have to
count to k + k/n. however, in the new k/n number, there are (k + k/n)/n - k/n numbers that are divisible by n, so those must also be counted...
continues on until ans/n - pre/n = 0;

(bit unclear and wrong variables, but kinda makes sense so whatever, just look at the code)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int T;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T--){
        ll n, k; cin >> n >> k;
        ll ans = k + k/n, pre = k;
        while (ans/n - pre/n > 0){
            // troublesome variable assignment here
            ll t = ans;
            ans += ans/n - pre/n;
            pre = t;
        }
        cout << ans << '\n';
    }
    return 0;
}