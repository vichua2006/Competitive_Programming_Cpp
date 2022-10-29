/*

very similar process as binary search. In fact, the number 17 is generated for the worst case scenario of the graph being linear, and performing
a binary search on that.

consider a node x with the most neighbors. By querying that node, we would know which section, or "branch", of the graph the rumor came from
it means that we only need to consider one of the components made by deleting node x. The rest of the graph is effectively non-existent. since worst case 
situation can still be computed within 17 queries (ceil(log2(2e5)) = 18, but we only need 17 to eliminate all but one possible node), we are guarenteed an answer
within 17 queries.

the specific process involves 3 dfs per query, one to "erase" the useless components and the other to recalculate the centroid of the new tree

don't have the correct defition of centroid.

see https://usaco.guide/plat/centroid?lang=cpp for details regarding centroid
so this was actually centroid decomposition, an actual technique.
I feel slightly proud for almost deriving it

wow the second dfs was actually not neeeded at all, I jsut needed to mark all the queries and make sure that future dfs doesn't get past them

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int s[maxN];
bool vis[maxN];
vector<int> g[maxN];

int get_centroid(int curr, int pre){
    // finding the centroid of the tree
    // just think about why this works
    for (int a: g[curr]){
        if (a == pre || vis[a]) continue;
        if (s[a] * 2 > N) return get_centroid(a, curr);
    }

    return curr;
}

void tsize(int curr, int pre){
    s[curr] = 1;
    // compute the size of the subtree with curr as its root
    for (int a: g[curr]){
        if (a == pre || vis[a]) continue;
        tsize(a, curr);
        s[curr] += s[a];
    }
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

    int centroid, query = 1;
    for (int i=0;i<17;i++){
        // get size of new graph
        tsize(query, 0);
        N = s[query];
        // get the centroid
        centroid = get_centroid(query, 0);
        vis[centroid] = 1;
        cout << centroid << '\n' << flush;
        cin >> query;

        if (!query) return 0;
    }

    // shouldn't ever get to here
    return 0;
}