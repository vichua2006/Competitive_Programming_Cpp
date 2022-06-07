/*

more recent version
still don't know how to prove that sum of convex functions is convex

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5+1,INF = 1e9;
int N;
ll P[maxN],W[maxN],D[maxN];

ll f_all(ll x){
    ll cnt = 0;
    for (int i=0;i<N;i++){
        if (!(P[i]-D[i]<=x&&x<=P[i]+D[i])){
            if (x < P[i]) cnt += W[i]*(P[i]-D[i]-x);
            else cnt += W[i]*(x-(P[i]+D[i]));
        }
    }
    return cnt;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++) cin >> P[i] >> W[i] >> D[i];

    ll a = 0,b = INF,ans = 0;
    while (a<=b){
        ll mid = (a+b)/2;
        ll l = f_all(mid-1),m = f_all(mid),r = f_all(mid+1);
        if (l>=m&&r>=m){
            ans = m;
            break;
        } else {
            if (m > l) b = mid-1;
            else a = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}