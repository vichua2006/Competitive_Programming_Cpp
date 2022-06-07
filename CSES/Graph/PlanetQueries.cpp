// sucessor graphs, characterized by the fact that it can defined as a function
//   x: 1 2 3 4...
//f(x): 3 5 4 8...
// furthermore, since the outdegree of each node is exactly 1, it means that there is a loop somewhere in the graph
// for computing where we end up after K steps for large K, binary search/jump can be applied
// let fN(x) denote the node we end up at after 2^N steps from x
// we are given f0(), so we can calculate f1(), then f2(),f4()... until the largest power of 2 less than K, which will take NlogK time
// after of which, each query can be answered in O(1) time, so the overall complexity is O(NlogK + Q)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
// log2(1e9=maxK) ~ 29, so 30 just to be safe
int N,Q,f[31][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=1;i<N+1;i++) cin >> f[0][i];
    for (int i=1;i<=30;i++){
        for (int j=1;j<N+1;j++){
            // fN(x) = fN-1(fN-1(x)), x first travels 2^(N-1) steps, then another 2^(N-1)
            f[i][j] = f[i-1][f[i-1][j]];
        }
    }
    for (int i=0;i<Q;i++){
        int a,b; cin >> a >> b;
        // we can answer queries in o(1) time by looking at the binary form of b:
        // if the ith bit of b is 1, it means it travels 2^(i-1) steps from a, which equals fi-1(a)
        // by shifting 1<<i, it is now at the i+1th bit
        for (int j=30;j>=0;j--){
            if (b&(1<<j)) a = f[j][a];
        }
        cout << a << '\n';
    }
    return 0;
}