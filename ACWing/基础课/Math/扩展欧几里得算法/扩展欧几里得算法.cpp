/*



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

void exgcd(int a, int b, int &x, int &y){
    // x, y must be passed in by reference for it to be updated
    if (!b){
        x = 1, y = 0;
        return;
    } 
    // switch x, y, so that y directly equals y', and x = x'
    exgcd(b, a % b, y, x);
    // divide first to prevent overflow
    y -= a / b * x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    while (N -- ){
        int a, b; cin >> a >> b;
        int x, y;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << '\n';
    }
    return 0;
}