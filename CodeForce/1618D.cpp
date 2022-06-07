// greedy, we want to get "rid" of as many large numbers as possible
// since each operation can erase two numbers and if a<b => floor(a,b) = 0
// we can erase the 2*k largest numbers, an-(2k-1),an-2k...an
// since if a = b, a/b = 1, we want as least of this situation as possible
// so we can let an, an-1...an-(k-1) be the denominators, and an-k...an-(2k-1) be the numerator, respectively
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e2 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int ii=0;ii<N;ii++){
        ll n,k,ans = 0; cin >> n >> k;
        // 1-indexed works better here
        for (int i=1;i<n+1;i++) cin >> arr[i];
        sort(arr+1,arr+n+1);
        // calculate all fractions
        for (int i=n;i>=n-k+1;i--){
            ans += arr[i-k]/arr[i];
        }
        for (int i=n-2*k;i>0;i--) ans += arr[i];
        cout << ans << '\n';
    }
    return 0;
}