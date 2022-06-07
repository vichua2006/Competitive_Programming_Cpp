//conditional if for parity, and then construct
// and use the time complexity to narrow down possible options
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

void OP(int n){
    for (int i=2;i<n+1;i+=2) cout << i << ' ';
    for (int i=1;i<n+1;i+=2) cout << i << ' ';
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    if (N<4&&N!=1){
        cout << "NO SOLUTION\n";
        return 0;
    }
    if (N&1) cout << N << ' ';
    OP(N-(N&1));
    return 0;

}