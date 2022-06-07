/*

for each given number, count all of its divisors
if are >= 2 of the same divisor, they are common
so find the largest i S.T. arr[i] >= 2

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1,INF = 1e9;
int N,arr[maxN];

void divisors(int x){
    if (x==1){
        arr[1] += 1;
        return;
    }
    for (int i=1;i*i<=x;i++){
        if (x%i==0){
            arr[i] += 1;
            if (i!=x/i) arr[x/i] += 1;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        divisors(a);
    }
    for (int i=maxN-1;i>=1;i--){
        if (arr[i]>=2){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}