/*

we can model the events as a directed graph
if i is prereq of j (i must be completed before j), then there should be an edge 
from i to j. we then perform tp sort, and remove nodes that are a part of a cycle
we remove nodes by setting their complete time (w[i]) to -1, indicating that they cannot 
be completed

then, we dp through the tp sort and compute for each (completeable) event,
the time it takes to complete it

the time it takes to complete event i with prerequisites r1,r2,..,rk is:

dp[i] = w[i] + max(r1,r2,...,rk)
(time = time to complete event i + time needed to complete all pre-reqs (
which equals the maximum time among r1-k))

if any of the pre-req cannot be completed, it means that i cannot be completed, either
in that case, we set w[i] = -1 as well, and exclude dp[i] from all future
computations, as Timmy will simply ignore that event == completion time is essentially 0

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1,INF = 1e9;
int N,dp[maxN];
int p[maxN],w[maxN];
bool visited[maxN],act[maxN];
vector<int> g[maxN],gin[maxN],tp;

void dfs(int curr){
    visited[curr] = 1,act[curr] = 1;
    for (int a:g[curr]){
        if (act[a]){
            w[a] = -1;
            int k = curr;
            while (k!=a){
                w[k] = -1,k = p[k];
            }
        }
        if (!visited[a]) p[a] = curr,dfs(a);
    }
    if (w[curr]!=-1) tp.push_back(curr);
    act[curr] = 0;
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=1;i<N+1;i++){
        int t,r; cin >> t >> r;
        w[i] = t;
        for (int j=0;j<r;j++){
            int a; cin >> a;
            g[a].push_back(i),gin[i].push_back(a);
        }
    }
    for (int i=1;i<N+1;i++){
        if ((!visited[i])&&w[i]!=-1) p[i] = i,dfs(i);
    }
    reverse(tp.begin(),tp.end());
    int ans = 0;
    for (int v:tp){
        if (w[v]==-1){
            dp[v] = -1;
            continue;
        }
        for (int a:gin[v]){
            dp[v] = max(dp[v],dp[a]);
            if (w[a]==-1) dp[v] = -1,w[v] = -1;
        }
        if (dp[v]!=-1) dp[v] += w[v];
        ans = max(ans,dp[v]);
    }
    cout << ans << '\n';
    return 0;
}