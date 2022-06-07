// greedy, the solution is always the median, or any number between the medians
// if the number was smaller that the median, the total sum would only decrease if we raise that number
// and vice versa, the same applies if the number is bigger than the median
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
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
    for (int i=1;i<N+1;i++) cin >> arr[i];
    sort(arr+1,arr+N+1);
    ll ans = 0,median = arr[N/2 + (N&1)];
    for (int i=1;i<N+1;i++) ans += abs(arr[i]-median);
    cout << ans << '\n';
    return 0;
}