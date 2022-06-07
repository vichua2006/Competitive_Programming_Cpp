#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,K;
bool arr[maxN];
int pre[maxN];

void setIO(string name){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("maxcross");

    cin >> N >> K >> M;
    for (int i=0;i<M;i++){
        int a; cin >> a;
        arr[a] = 1;
    }
    for (int i=1;i<N+1;i++) pre[i] = pre[i-1] + arr[i];
    int ans = INF;
    // compute how many broken lights are in the interval [i,i+K-1] (i+K would be K=1 lights)
    // and because of that, i < N+1-K+1, not i < N+1-K, because then we would never use the range
    // [N-K+1,N], and subsequently get WA in test case 11 (hah figured this out without looking 
    // at the test data)
    for (int i=1;i<N+1-K+1;i++) ans = min(ans,pre[i+K-1]-pre[i-1]);
    cout << ans << '\n';
    return 0;
}