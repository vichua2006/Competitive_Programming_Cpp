// binary search with equation, search for point where # of emoji exceeds x
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll compute_emo(ll a,ll k){
    //computes the # of emotes after sending the ath message
    ll s = 0;
    if (a <= k){
        s += (a+1)*a/2;
    }
    else{
        // extra calculations are needed for messages after the kth one
        // total emo = 2*(k*(k-1)/2) + k = k*k
        // then subtract number of missing messages to complete the trangle
        s += k*k;
        ll m = 2*k-1-a;
        s -= (m+1)*m/2;
    }
    return s;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int t=0;t<N;t++){
        ll k,x,p = 0; cin >> k >> x;
        // binary search for the maximum number of sent messages
        for (ll b=2*k-1;b>=1;b/=2){
            // NOTE two small details: c(p+b,k) STRICTLY LESS THAN x, and: p+b STRICTLY LESS THAN  2k-1
            // because, if <= is used, we will not be able to consistantly get the correct p as we are looking for the first p S.T. c(p) >= x
            // if here, c(p) < x, p is as great as possible, then c(p+1) will for sure exceed x
            while(compute_emo(p + b,k) < x&& p+b < 2*k-1){
                p += b;
            }
        }
        cout << p+1 << '\n';
    }
    return 0;
}