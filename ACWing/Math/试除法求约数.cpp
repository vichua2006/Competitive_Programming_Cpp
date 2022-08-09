/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
set<int> res;

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
        res.clear();
        for (int i=1;i<=a/i;i++){
            if (a % i == 0){
                res.insert(i);
                res.insert(a / i);
            }
        }
        for (int a: res) cout << a << ' ';
        cout << '\n';
    }
    return 0;
}