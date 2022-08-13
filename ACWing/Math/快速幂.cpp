/*

kinda like binary jump, so each computation will take O(logb) times, so n computations will 
take O(nlogn) time

what this is actually doing is breakig b down into a binary number and piecing it together with a^2^0, a^2^1, a^2^2, a^2^4 ...

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll f(ll a, ll b, ll p){
    int res = 1;
    while (b > 0){
        if (b&1){
            res = (res * a) % p;
            b -= 1;
        } else {
            a = (a * a) % p;
            b /= 2;
        }
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    while (N -- ){
        ll a, b, p; cin >> a >> b >> p;
        cout << f(a, b, p) << '\n';
    }

    return 0;
}