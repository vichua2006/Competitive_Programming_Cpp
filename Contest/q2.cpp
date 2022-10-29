/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int T, N, M;    

int main(){
    // cin.tie(0);
    // cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    for (int t=0;t<T;t++){
        cin >> N >> M;
        int d = M / N, r = M % N;
        if (((N - 1) % 2 == 0 || r == 0) && d != 0){
            cout << "Yes\n";
            for (int i=0;i<N-1;i++) cout << d << ' ';
            cout << d + r << '\n';
        } else if (r % 2 == 0){
            cout << "Yes\n";
            for (int i=0;i<N-2;i++) cout << d << ' ';
            cout << d + r / 2 << ' ' << d + r / 2 << '\n';
        }
        else {
            cout << "No\n";
        }
    }
}