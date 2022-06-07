// these are "simple" implementation problems
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    cout << N << ' ';
    while (N!=1){
        if (N%2 == 0) N /= 2;
        else N = 3*N + 1;
        cout << N << ' ';
    }
    return 0;
}