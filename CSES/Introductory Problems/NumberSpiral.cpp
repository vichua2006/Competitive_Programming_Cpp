// implementation and a bit of math
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,ans;

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
        ll x,y; cin >> y >> x;
        if (x>=y){
            //if x is odd
            if (x&1) ans = x*x - y + 1;
            else ans = (x-1)*(x-1)+1 + y - 1;
        }
        else{
            if (y&1) ans = (y-1)*(y-1)+1 + x - 1;
            else ans = y*y - x + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}