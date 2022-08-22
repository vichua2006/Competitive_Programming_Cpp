/*

for each node n in the tree, there are two possiblities

either we choose to include the n, or we don't

case 1: include

then for each subtree under n with its children as the root, the maximum value each subtress could offer is 
dcon[i] for each child i, since the direct child cannot be chosen whatsoever

inc[n] = exc[k1] + exc[k2] +...

case 2: exclude

in this case, for each subtree, we get to choose which value we want to use (we get to choose to include or
exclude the root of that subtree)

exc[n] = max(inc[k1], exc[k1]) + max(inc[k2], exc[k2]) +...

answer is max(inc[i], exc[i]) for each node i, since the weight they carry could be negative

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, ans = -INF;
int arr[maxN], inc[maxN], exc[maxN];
vector<int> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int curr, int pre){
    for (int a : g[curr]){
        if (a != pre){
            dfs(a, curr);
            // compute dp values
            inc[curr] += exc[a];
            exc[curr] += max(inc[a], exc[a]);
        }
    }
    inc[curr] += arr[curr];

    ans = max(ans, max(inc[curr], exc[curr]));
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> arr[i];
    for (int i=0;i<N-1;i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }

    dfs(1, 0);

    cout << ans << '\n';

    return 0;
}