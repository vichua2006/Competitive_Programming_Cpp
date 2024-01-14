/*

dsu
a hint comes from the second subtask, where all the edges are either weighted 0 or 1
we can dfs the graph and record all components that are connected by edges with weight 0
then for each query, we check if x and y are in the same component, if they are, then the answer is 0, and otherwise is 1

since k is small (< 100 = 1 << 5 + 1 << 6), the max answer is at most (1 << 7) - 1
thus, we can do a dsu for each possible k, and check if the two nodes are connected
if it is, since we are doing in ascending order of k, then it is the answer

an edge is included in the graph if its bits are a subset of the current value of k
(in other words, k | wi = k)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M, Q;
int l[maxN], s[maxN], ans[maxN];
vector<ar<int, 2>> qry;
vector<ar<int, 3>> edges;

int find(int x){
    if (x != l[x]) l[x] = find(l[x]);
    return l[x];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> Q;
    for (int i=0;i<M;i++){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    for (int i=0;i<Q;i++){
        int a, b; cin >> a >> b;
        qry.push_back({a, b});
    }

    memset(ans, -1, sizeof(ans));
    for (int k=0;k<(1<<7);k++){
        for (int i=1;i<N+1;i++) l[i] = i, s[i] = 0;

        for (auto e : edges){
            int a = e[0], b = e[1], c = e[2];
            if ((c | k) != k) continue;
            int na = find(a), nb = find(b);
            if (na != nb){
                if (s[na] < s[nb]) swap(na, nb);
                l[nb] = na;
                s[na] += s[nb];
            }
        }

        for (int i=0;i<Q;i++){
            int a = qry[i][0], b = qry[i][1];
            if (ans[i] > -1) continue;
            if (find(a) == find(b)) ans[i] = k;
        }
    }

    for (int i=0;i<Q;i++) cout << ans[i] << '\n';

    return 0;
}