/*

refer to the analysis markdown file in the same folder

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
unordered_map<ll, ll> d;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
void get_fn(ll n){
    ll res = 1;
    for (int i=2;i<=n/i;i++){
        ll cnt = 0;
        while (n % i == 0) n /= i, cnt ++ ;
        d[i] += cnt;
    }
    if (n > 1) d[n] += 1;
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    while (N -- ){
        ll a; cin >> a;
        get_fn(a);
    }
    ll res = 1;
    for (auto a : d){
        ll p = a.first, alpha = a.second, sum = 1, pp = p;
        for (int i=0;i<alpha;i++){
            sum = (sum + pp) % MOD;
            pp = (pp * p) % MOD;
        }
        res = (res * sum) % MOD;
    }
    cout << res << '\n';
    return 0;
}