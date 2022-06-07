#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,arr[maxN],ans = 0;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i];
    for (int i=1;i<N;i++){
        if (arr[i] < arr[i-1]){
            ans += arr[i-1]-arr[i];
            arr[i] = arr[i-1];
        }
    }
    cout << ans << '\n';
    return 0;
}