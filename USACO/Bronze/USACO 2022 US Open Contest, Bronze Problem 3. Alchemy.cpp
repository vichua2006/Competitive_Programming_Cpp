/*

recursion
f(x) denotes the maximum number of metal x that can be obtained
however, it may not be possible to simultaneously obtain maximum number of different metals, as they may conflict in resources

instead, f(x) can return whether x can be produced, and if so, subtract the materials used.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int arr[maxN];
vector<int> g[maxN];

bool f(int x){
    // if metal x already exist, use it
    if (arr[x]){
        arr[x] -- ;
        return true;
    }

    // otherwise, check if it is possible to create metal x
    bool val = true;
    for (int m : g[x]) val &= f(m);

    // there needs to be a way to create the metal for this to be true
    return val && (g[x].size() != 0);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> arr[i];
    cin >> M;
    for (int i=0;i<M;i++){
        int a, b; cin >> a >> b;
        for (int j=0;j<b;j++){
            int c; cin >> c;
            g[a].push_back(c);
        }
    }

    int cnt = 0;
    // count the number of times N can be produced
    while (f(N)) cnt ++ ;
    cout << cnt << '\n';

    return 0;
}