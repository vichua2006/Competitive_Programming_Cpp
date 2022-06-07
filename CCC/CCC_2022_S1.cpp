#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    int cnt = 0;
    for (int i=0;i<=N/5;i++){
        if ((N-5*i)%4==0) cnt += 1;
    }
    cout << cnt << '\n';
    return 0;
}