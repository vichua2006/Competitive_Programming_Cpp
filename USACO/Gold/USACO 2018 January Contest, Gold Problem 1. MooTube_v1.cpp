/*

conclusion: if its a graph and it asks for min distance for between nodes, and its not warshell, then it's probably dsu with
a special property with the edge weights

if it's a tree and asking for distance, probably LCA or just dfs

and in this case, asking if two nodes are connected, or how many nodes are connect, is probably again dsu

in this case, order the edges from greatest relevance to least, and do the same for queries.
iterate through the edges and add them in, and for each addition, process the queries that require at least
relevance of r, where r is the relevance of the current edge. since all unadded edges have relevance less than r,
the only videos that are connected with a min. relevance of r are the currently connect components.

therefore, the answer is s[i] for each node i as edges are being added

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, Q;
int l[maxN], s[maxN], ans[maxN], ordered_qry[maxN];
vector<ar<int, 3>> edges;
vector<ar<int, 2>> queries;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool comp(int a, int b){
    return queries[a][0] > queries[b][0];
}

int find(int x){
    if (x != l[x]) l[x] = find(l[x]);
    return l[x];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO("mootube");

    cin >> N >> Q;
    for (int i=1;i<N+1;i++) l[i] = i, s[i] = 1, ordered_qry[i - 1] = i - 1;
    for (int i=0;i<N-1;i++){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    for (int i=0;i<Q;i++){
        int a, b; cin >> a >> b;
        queries.push_back({a, b});
    }


    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    sort(ordered_qry, ordered_qry + Q, comp);

    int idx = 0;
    for (auto e : edges){
        int c = e[0], a = e[1], b = e[2];
        int na = find(a), nb = find(b);
        if (na != nb){
            if (s[na] < s[nb]) swap(na, nb);
            l[nb] = na;
            s[na] += s[nb];
        }

        while (idx < Q && queries[ordered_qry[idx]][0] >= c){
            int v = queries[ordered_qry[idx]][1];
            ans[ordered_qry[idx]] = s[find(v)] - 1;
            idx ++ ;
        }
    }

    // for the situation where there are still queries remaining after the last edge was added
    while (idx < Q){
        int v = queries[ordered_qry[idx]][1];
        ans[ordered_qry[idx]] = s[find(v)] - 1;
        idx ++ ;
    }

    for (int i=0;i<Q;i++) cout << ans[i] << '\n';

    // for (int i=0;i<Q;i++) cout << ordered_qry[i] << '\n';

    return 0;
}