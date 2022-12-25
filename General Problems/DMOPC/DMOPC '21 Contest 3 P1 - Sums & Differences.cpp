/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
ll ans[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    // x - y, 2y
    ll a, b;
    for (int i=1;i<=N/2;i++){
        int j = N - i + 1;
        cout << "? " << i << ' ' << j << '\n';
        cout << flush;

        cin >> a;
        cout << "? " << i << ' ' << j << '\n';
        cout << flush;

        cin >> b;
        int y = b / 2, x = a + y;
        ans[i] = x, ans[j] = y;
    }

    if (N & 1){
        cout << "? " << N / 2 + 1 << ' ' << 1 << '\n';
        cout << flush;

        cin >> a;
        ans[N / 2 + 1] = a + 2 * ans[1];
    }

    cout << "! ";
    for (int i=1;i<N+1;i++) cout << ans[i] << (i == N ? '\n' : ' ');
    cout << flush;

    return 0;
}