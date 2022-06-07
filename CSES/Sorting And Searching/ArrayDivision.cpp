/*

translate into prefix sums: the sum of interval [i,j] is only divisible by N
when pre[j] = pre[i-1] (mod N)
so we keep tract of array rem where rem[i] = number of pre[k]%N==i
since the sum could be negative, the modulus may need to be adjusted
which isn't that difficult since modular things are defined for negative values

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
// rem[i] = number of pre[k] whose sum = i (mod N)
ll rem[maxN];

void setIO(string name){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO("hps");

    cin >> N;
    ll sum = 0,cnt =0 ;
    rem[0] += 1;
    for (int i=0;i<N;i++){
        ll a; cin >> a;
        sum += a;
        ll r = sum%N;
        if (r<0) r += N;
        cnt += rem[r];
        rem[r] += 1;
    }
    cout << cnt << '\n';
    return 0;
}