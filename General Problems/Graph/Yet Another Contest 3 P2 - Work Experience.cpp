/*

let d(a, b) denote the distance between node a and b

first, realize the solution to the first subtask:
for any three points that are on the same path (from the left-most node, a, to the right-most node, b), there is only one possible node n such that
d(a, n) + d(b, n) + d(c, n) reaches it's minimum: n = c (the middle node)

(any node outside of a or b is clearly not the opimal solution)

for any node x between a and b, the sum d(a, x) + d(b, x) = d(a, b) remains the same. only d(c, x) changes when x change.
thus, we find x such that d(c, x) is at its min, which is x = c.

the same thought can be extended onto three-end situations. c is no longer on the path of a to b, but connects to it:

a-----------------b
        |
        |
        |
        c

again, d(a, x) + d(b, x) does not change for any x in between a, b, so d(c, x) must be at min, which means that the desired node n
must be at where c joins the path of a, b. note that any node on the path of c is not the optimal solution. d(c, x) will decrease by 1, but 
d(a, x) + d(b, x) will increase by 2, which makes + 1 overall.

hence, for any node k, there are 4 possible situations where satisfy the minimum distance requirement
1. k is on the path of (a, b), (b, c), and (c, a), but is not directly on any of a, b, or c 
2. one of a, b, c is on k, and k is on the path of the other 2
3. two of a, b, c is on k, 
4. all three are on k

to compute all possible permuations of (a, b, c) for a node k, 
suppose (y1, y2, y3,..., ym) are the neighbors of k, and let S(yi) denote the size of the compnent yi belongs to
if k was erased from the tree. 
for each situation:
1. iterate triplets (yi, yj, yk) and add 6 * S(yi) * S(yj) * S(yk) to ans (one node from each branch)
2. iterate pairs (yi, yj) and add 6 * S(yi) * S(yj) to ans (one node sits on k)
3. iterate yi, and add 3 * S(yi) to ans (two sit on k, and the third is in one of the m branches)
4. add 1 to ans (all three are on k)

this has a time complexity of O(N^3), which passes only the first 3 subtasks


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 3e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
ll ans[maxN];
vector<int> g[maxN];
// there was another version that declared a nei per dfs call, but I thought that it would take too
// much time to allocate them during runtime. Not that it made much of a difference
vector<ll> nei[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}   

ll dfs(int curr, int pre){
    ll cnt = 0;
    for (int a : g[curr]){
        if (a != pre){
            ll res = dfs(a, curr);
            nei[curr].push_back(res);
            cnt += res;
        }
    }
    nei[curr].push_back(N - 1 - cnt);

    int n = nei[curr].size();
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            for (int k= j+1;k<n;k++){
                ans[curr] += 6 * nei[curr][i] * nei[curr][j] * nei[curr][k];
            }
            ans[curr] += 6 * nei[curr][i] * nei[curr][j];
        }
        ans[curr] += 3 * nei[curr][i];
    }
    ans[curr] += 1;

    return cnt + 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N-1;i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    dfs(1, 0);

    for (int i=1;i<N+1;i++) cout << ans[i] << (i == N ? '\n' : ' ');

    return 0;
}