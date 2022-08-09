/*

even this;
realize that in there will only be at most one prime factor of n that is larger than sqrt(n)

if there are two, then those multiplied together will, exceed n, which is a contradiction
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
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    while (N --){
        int a; cin >> a;
        for (int i=2;i<=a/i;i++){
            int cnt = 0;
            while (a % i == 0) cnt += 1, a /= i;
            if (cnt) cout << i << ' ' << cnt << '\n';
        }
        // need to remember to check what is left of a; it could still be a prime larger than sqrt(a), which wouldn't get picked
        if (a > 1) cout << a << ' ' << 1 << '\n';
        cout << '\n';
    }
    return 0;
}