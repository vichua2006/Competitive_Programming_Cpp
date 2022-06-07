/*

link: https://dmoj.ca/problem/sac22cc3p4

to find the distance between any two nodes of a (lets just assume it's rooted) tree
we can compute their least common ancestor (LCA) and use that to compute the distance

more specifically, let d(node1,node2) denote the distance between node1 and node2
let r be the root node

therefore,

    d(a,b) = d(r,a) + d(r,b) - 2*d(r,lca(a,b))

we can query lca(a,b) with binary lifting in O(log(N)) with O(Nlog(N)) preprocessing
and query d(r,a or b) in O(1) by performing dfs search from r, O(N+N-1) preprocessing

as for the removing edges part, we use a DSU (what a surprise), but instead of
processing the queries in the given order (becasue IDK how to remove connections)
we reverse the order and add edges

time complexity: O(2Nlog(N) + Qlog(N))
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 18,INF = 1e9, MOD = 1e9 + 7;
int N,Q,t = 0;
// log2(1e5) ~ 18
// anc[i][j] = i's 2 to the jth ancestor,dis,DSU,start/finish time
int anc[maxN][maxK],dis[maxN],s[maxN],l[maxN],st[maxN],et[maxN];
ar<int,3> req[2*maxN];
vector<int> g[maxN];

int lca(int a,int b){
    for (int i=maxK-1;i>=0;i--){
        int na = anc[a][i];
        if (st[na]<st[b]&&et[b]<et[na]) continue;
        a = na;
    }
    return a;
}

int find(int x){
    while (x!=l[x]) x = l[x];
    return x;
}

void dfs(int curr,int pre){
    t += 1;
    st[curr] = t,anc[curr][0] = pre;
    for (int a:g[curr]){
        if (a!=pre){
            dis[a] = dis[curr] + 1;
            dfs(a,curr);
        }
    }
    t += 1;
    et[curr] = t;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=0;i<N+1;i++) s[i] = 1,l[i] = i;
    for (int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b),g[b].push_back(a);
    }
    for (int i=0;i<Q;i++){
        int a,b,c; cin >> a >> b >> c;
        req[i] = {a,b,c};
    }
    reverse(req,req+Q);
    // root the tree at node 1, since its guaranteed to exist
    dfs(1,1);
    // compute anc[i][1] - anc[i][logN]
    for (int i=1;i<maxK;i++){
        for (int j=1;j<N+1;j++){
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
    // process queries in reverse order
    vector<int> ans;
    for (int i=0;i<Q;i++){
        int a = req[i][0],b = req[i][1],c = req[i][2];
        if (a-1){
            b = find(b),c = find(c);
            if (b!=c){
                if (s[b]<s[c]) swap(b,c);
                l[c] = b;
                s[b] += s[c];
            }
        } else {
            int nb = find(b),nc = find(c);
            if (nb!=nc) ans.push_back(-1);
            else {
                if (st[b]<st[c]&&et[c]<et[b]) ans.push_back(dis[c]-dis[b]);
                else {
                    if (st[c]<st[b]&&et[b]<et[c]) ans.push_back(dis[b]-dis[c]);
                    else {
                        int node = lca(b,c),ancestor = anc[node][0];
                        ans.push_back(dis[b]+dis[c]-2*dis[ancestor]);
                    }
                }    
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for (int a:ans) cout << a << '\n';
    return 0;
}