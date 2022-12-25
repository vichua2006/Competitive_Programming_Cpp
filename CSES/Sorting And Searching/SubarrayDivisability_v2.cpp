/*
 
this solution is fundamentally the same thing, but computes the final answer as it counts
 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array
 
const int maxN = 2e5 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
ll arr[maxN];
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
 
    cin >> N;
    ll sum = 0, cnt = 0;
    arr[0] = 1;
    for (int i=0;i<N;i++){
        ll a; cin >> a;
        sum += a;
        cnt += arr[((sum % N) + N) % N] ++ ;
    }
 
    cout << cnt << '\n';
}