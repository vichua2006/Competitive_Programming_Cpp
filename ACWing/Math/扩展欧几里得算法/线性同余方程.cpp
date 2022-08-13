/*

this can be solved with the extended euclidean algorithm

ax = b (mod m) => ax = my + b

let y' = -y

therefore,  ax + my' = b

bezout's theorem holds true for any ax + by = k(a, b), so we just have to check if b is a multiple of (a, m)

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

int gcd(int a, int b, int &x, int &y){
    // okay so this solves for (x, y) in ax + by = (a, b)
    if (b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    while (N -- ){
        int a, b, m; cin >> a >> b >> m;
        int x, y;
        int d = gcd(a, m, x, y);
        // however, the actual number b might be a multiple of (a, m), or k(a, m)
        // the x we compute only satisfies ax + my' = (a, m), so in order for it to satisfy  ax + my' = **k**(a, m) = b, 
        // it has to be multiplied by b / d (= k), and then moded by m to ensure that it remains an int
        if (b % d == 0) cout << (b / d * x) % m << '\n';
        else cout << "impossible\n";
    }

    return 0;
} 