/*

editorial: https://codeforces.com/blog/entry/76352

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int T, N;
ll arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T--){
        cin >> N;
        for (int i=0;i<N;i++) cin >> arr[i];
        ll sum = 0, msf = arr[0];
        for (int i=1;i<N;i++){
            if (arr[i] * arr[i-1] < 0) sum += msf, msf = arr[i];
            msf = max(msf, arr[i]);
        }
        sum += msf;
        cout << sum << '\n';
    }
    return 0;
}