// intersting math problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll T,N;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while(T--){
        cin >> N;
        ll srN = (ll)sqrt(N);
        ll crN = (ll)cbrt(N);
        // count overlap-must be power of 6
        ll cnt = 1;
        while(cnt*cnt*cnt*cnt*cnt*cnt<=N){
            cnt += 1;
        }
        cout << srN + crN - cnt + 1<< '\n';
    }
    return 0;
}