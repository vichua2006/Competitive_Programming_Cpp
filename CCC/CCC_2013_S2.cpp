// somewhat illogical setting, but ok
// prefix sum is used here, if arr[i]-arr[i-4] > w, then only i-1 trains are allowed to pass

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1e6 + 1;

int n,w,arr[maxN],sum = 0;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> w >> n;
    for (int i=1;i<n+1;i++){
        int a; cin >> a;
        arr[i] = a + arr[i-1];
    }
    for (int i=1;i<n+1;i++){
        // i needs to be greater than or equal to 4 for subtraction
        if (arr[i] - arr[i-4]*(i>=4) > w){
            cout << i-1 << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    return 0;
}
