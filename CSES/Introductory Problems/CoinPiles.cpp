// in other words, start from (0,0) and using those two operations, is it possible to build up to (a,b)?
// let k be the number of times (2,1) is added and let l be the number of times (1,2) is added
// therefore a = 2k + l, b = 2l + k, does there exist k,l?
// hence, at the very least, 3|a+b. let q = (a+b)/3 => q - l= k, q - k = l
// => a - q = k, b - q = l, and k,l are non-negative int
// so we only need to check 1) 3|a+b 2) a-q >= 0, b-q >= 0
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
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++){
        ll a,b; cin >> a >> b;
        if ((a+b)%3 != 0){
            cout << "NO\n";
            continue;
        }
        ll q = (a+b)/3;
        if ((b-q>=0)&&(a-q>=0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}