/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
ll x, y;
char a = 'A', b = 'B';

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> x >> y;
    if (x > y) swap(x, y), swap(a, b);

    vector<ar<char, 3>> operations;
    while (x){
        if (x & 1) operations.push_back({b, 'C', 'C'});
        operations.push_back({b, b, b});
        x /= 2;
    }
    cout << operations.size() << '\n';
    for (auto a : operations) cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    cout << "C\n";
    return 0;
}