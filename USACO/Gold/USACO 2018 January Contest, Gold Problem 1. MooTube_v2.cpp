/*

update: the outside loop should be the queries instead of the edges. for each query, add in all edges with
a relevance that is greater than or equal to that of the query.

the previous version encounters problems when there are multiple edges of the same weight
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
    setIO("mootube");

    cin >> N >> Q;
    for (int i=1;i<N+1;i++) l[i] = i, s[i] = 1;
    for (int i=0;i<Q;i++) ordered_qry[i] = i;
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
    for (int i=0;i<Q;i++){
        int k = queries[ordered_qry[i]][0], v = queries[ordered_qry[i]][1];
        for (; idx < N - 1 && edges[idx][0] >= k;idx++){
            auto e = edges[idx];
            int c = e[0], a = e[1], b = e[2];
            int na = find(a), nb = find(b);
            if (na != nb){
                if (s[na] < s[nb]) swap(na, nb);
                l[nb] = na;
                s[na] += s[nb];
            }
        }
        
        ans[ordered_qry[i]] = s[find(v)] - 1;
    }

    for (int i=0;i<Q;i++) cout << ans[i] << '\n';

    return 0;
}