#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t,n,ans; cin >> t;
    for (int i=0;i<t;i++){
        cin >> n;
        ans = n/10;
        if (n%10 == 9) ans += 1;
        cout << ans << '\n';
    }
    return 0;
}