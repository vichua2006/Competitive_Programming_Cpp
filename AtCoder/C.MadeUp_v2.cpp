#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 1e5+1;
int a[maxN],b[maxN],c[maxN],cc[maxN],n,m;
ll ans =0 ;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){cin >> m;a[i] = m-1;}
    for (int i=0;i<n;i++){cin >> m;b[i] = m-1;}
    for (int i=0;i<n;i++){cin >> m;c[i] = m-1;}
    // precalculate all the values of j such that bcj = i
    for (int i=0;i<n;i++){
        cc[b[c[i]]] += 1;
    }
    for (int i=0;i<n;i++){
        ans += (ll) cc[a[i]];
    }
    cout << ans << '\n';
    return 0;
}
