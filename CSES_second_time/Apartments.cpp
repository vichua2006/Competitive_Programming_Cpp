/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,M,K,aprt[maxN],app[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> K;
    for (int i=0;i<N;i++) cin >> app[i];
    for (int i=0;i<M;i++) cin >> aprt[i];
    sort(app,app+N),sort(aprt,aprt+M);
    int a = 0,b = 0,cnt = 0;
    while (a<N&&b<M){
        if (app[a]-K<=aprt[b]&&aprt[b]<=app[a]+K){
            cnt += 1, a += 1, b += 1;
        }
        else {
            if (app[a]-K>aprt[b]) b += 1;
            if (app[a]+K<aprt[b]) a += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}