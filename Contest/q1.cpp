/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
ll arr[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=2;i<N+1;i++){
        string name; cin >> name;
        if (name[0] == 'P') cin >> arr[i];
        else {
            ll a, b; cin >> a >> b;
            arr[i] = b + arr[a];
        }
    }

    ll res = 0x3f3f3f3f3f3f3f3f;
    for (int i=1;i<N;i++) res = min(res, arr[i + 1] - arr[i]);
    for (int i=1;i<N;i++){
        if (res == arr[i + 1] - arr[i]){
            cout << res << ' ' << i << ' ' << i + 1 << '\n';
            break;
        }
    }

    return 0;
}