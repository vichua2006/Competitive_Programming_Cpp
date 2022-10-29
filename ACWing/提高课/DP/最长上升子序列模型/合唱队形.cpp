/*

exact same problem as before, literally changed the output and ACed

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN], lis[maxN], lds[maxN];

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
    int msf = 0;
    // compute lis for all k
    for (int i=1;i<N+1;i++){
        for (int j=0;j<i;j++){
            if (arr[j] < arr[i] ) lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    // compute lds starting at all k
    reverse(arr + 1, arr + N + 1);
    for (int i=1;i<N+1;i++){
        for (int j=0;j<i;j++){
            if (arr[j] < arr[i] ) lds[i] = max(lds[i], lds[j] + 1);
        }
    }
    reverse(lds + 1, lds + N + 1);
    for (int i=1;i<N+1;i++) msf = max(msf, lis[i] + lds[i] - 1);

    cout << N - msf << '\n';
    return 0;
}