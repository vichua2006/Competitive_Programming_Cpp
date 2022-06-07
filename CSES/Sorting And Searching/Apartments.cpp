//first sort the two arrays, then, two-pointer my way through
//the smallest apartment should go to the person requesting the smallest size
//if the smallest aprt can't satisfy it, none can.
// then, after assigning that, a new "smallest apartment" and "smallest request" appearrs
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,K,A[maxN],B[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> K;
    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<M;i++) cin >> B[i];
    sort(A,A+N),sort(B,B+M);
    int a = 0,b = 0,cnt = 0;
    while(a<N&&b<M){
        if (A[a]-K<=B[b]&&B[b]<=A[a]+K){
            // fits, goes to next pair
            cnt += 1,a += 1,b += 1;
        }
        // if the current apartment is too small for even the smallest request
        if (B[b]<A[a]-K) b += 1;
        // if the request is smaller than the smallest aprt.
        else if (A[a]+K<B[b]) a += 1;
    }
    cout << cnt << '\n';
    return 0;
}