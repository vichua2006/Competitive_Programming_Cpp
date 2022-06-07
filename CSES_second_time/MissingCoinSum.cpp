#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 2e5 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
ll N,arr[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i];
    sort(arr,arr+N);
    ll msf = 0;
    for (int i=0;i<N;i++){
        if (arr[i] <= msf+1){
            msf += arr[i];
        } else {
            cout << msf+1 << '\n';
            return 0;
        }
    }
    cout << msf+1 << '\n';
    return 0;
}