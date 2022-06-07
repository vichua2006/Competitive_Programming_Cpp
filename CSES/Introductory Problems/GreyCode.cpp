//generating permutations, but in a specific order
// to convert from binary to grey code, Gi = Bi^(B(i+1)), where bi is the binary equalvent
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
    for (int i=0;i<1<<N;i++){
        for (int j=N;j>=1;j--){
            // (1<<j)&i = bj will return whether the jth bit of i is 1 or 0
            // (1<<(j-1))&i = b(j-1) will return the j-1th bit of i
            // so, gj = bj^b(j-1)
            bool b1 = (1<<j)&i, b2 = (1<<(j-1))&i;
            bool ans = b1^b2;
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}