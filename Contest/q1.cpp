/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int T, N;
int arr[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    for (int t =0;t<T;t++){
        cin >> N;
        for (int i=0;i<N;i++) cin >> arr[i];
        int res = -INF;
        for (int i=0;i<N;i++) res = max(res, arr[(i + N - 1) % N] - arr[i]);

        int msf = -INF;
        for (int i=1;i<N;i++) msf = max(msf, arr[i]);
        res = max(res, msf - arr[0]);

        msf = INF;
        for (int i=0;i<N-1;i++) msf = min(msf, arr[i]);
        res = max(res, arr[N - 1] - msf);

        cout << res << '\n';
    }

    return 0;
}