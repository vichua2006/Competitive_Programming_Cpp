/*

classic two pointer

sort the diamonds, and two pointer through it; increase b if the current difference
<= K, else increase A. 
follow the recursive logic: to include the new b, a must be larger, thus increases a

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1, INF = 1e9, MOD = 1e9 + 7;
int N, K;
int arr[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> K;
    for (int i=0;i<N;i++) cin >> arr[i];
    sort(arr, arr+N);
    int a = 0, b =0, msf = 0;
    while (b < N){
        if (arr[b]-arr[a] <= K) msf = max(msf, b-a+1), b += 1;
        else a += 1;
    }
    cout << msf << '\n';
    return 0;
}