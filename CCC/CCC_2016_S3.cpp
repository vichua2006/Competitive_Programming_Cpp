//very interesting tree problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,nei[maxN],dis[maxN];
bool exist[maxN],pho[maxN];
vector<int> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void bfs(){
    vector<int> q;
    for (int i=0;i<N;i++){
    // all nodes n with nei[n] = 1 are leaves; use multisource b/dfs
    // to prun unessecery leaves; if you are a leaf and not a pho restaurant
    // you do not need to be visited
        if (nei[i]==1) q.push_back(i);
    }
    while(q.size()){
        int v = q.back(); q.pop_back();
        if (nei[v]>1||pho[v]||!(exist[v])) continue;
        exist[v] = false;
        nei[v] -= 1;
        for (int a:g[v]){
            if (exist[a]) {
                q.push_back(a);
            }
            nei[a] -= 1;
        } 
    }
}

int find_max(){
    int x = 0;
    for (int i=0;i<N;i++){
        if (dis[i] > dis[x]) x = i;
    }
    return x;
}

void dfs(int curr,int pre){
    for(int a:g[curr]){
        if (a != pre&&exist[a]){
            dis[a] = dis[curr] + 1;
            dfs(a,curr);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<M+1;i++) {
        int a; cin >> a;
        pho[a] = true;
    }
    for (int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b),g[b].push_back(a);
        // record number of neighbors each node has
        nei[a] += 1, nei[b] += 1;
    }
    // pruning; see bfs comments
    memset(exist,1,sizeof(exist));
    bfs();
    // find diameter
    // OH MY F#$@ GOD I FOUND WHY I AM NOT PASSING THESE THINGS11
    // here is my previous code: dfs(0,-1);
    // see what's wrong? answer: 0 might not exist
    for (int i=0;i<N;i++){
        if (exist[i]){
            dfs(i,-1);
            break;
        }
    }
    int d = find_max();
    dis[d] = 0; dfs(d,-1);
    d = find_max();
    // so with the current tree, each leaf node must be visited once, which
    // means that if you start on node a, visite all pho restaurants, and return to a
    // we would traverse all edges twice (travers all nodes); since each has weigth of 1, it would take
    // 2*(N-1) minutes.
    // the catch is that we don't have to return to the original node; this means
    // that there will be exactly one path in the tree that is traversed once, the rest twice
    // so it will take Jo 2*(N-1) - length_of_that_path
    // to minimize this number, we maximize length_of_that_path
    // aka longest path in a tree
    // aka the diameter (of the pruned tree, not the original one);
    int newN = 0; for (int i=0;i<N;i++) newN += exist[i];
    cout << 2*(newN-1) - dis[d] << '\n';
    return 0;
}