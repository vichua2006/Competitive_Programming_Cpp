#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 2e5 + 1,maxM = 101,maxK = 0,INF = 1e18, MOD = 1e9 + 7;
int N,ssq[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    memset(ssq,0x3f,sizeof(ssq));
    int ans = 0;
    for (int i=0;i<N;i++){
        int a,p = 0; cin >> a;
        for (int b=N;b>=1;b/=2){
            while (p+b<=N && a>ssq[p+b]) p += b;
        }
        ssq[p+1] = min(ssq[p+1],a);
        ans = max(ans,p+1);
    }
    cout << ans << '\n';
    return 0;
}