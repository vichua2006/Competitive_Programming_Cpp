/*

for each node, we compute the largest component that would result form deleting that node

in a tree, the number of components that result from removing a node equals the node's indegree
e.g. if node n is connected to three different nodes, then taking out n would result in three seperate components

hence, we can use recursive dfs:
dfs(curr,pre) returns the component size of the subtree with root curr, excluding the subtree with node pre
in the function, the resulting sizes of removing node curr is computed and used to update the final answer
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 101,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,min_com = INF;
int ind[maxN];
vector<int> g[maxN];

int dfs(int curr,int pre){
    // cnt = size of component,msf = max of component size resulting from removing curr
    int cnt = 0,msf = 0;
    for (int a:g[curr]){
        if (a!=pre){
            // component size of a
            int res = dfs(a,curr);
            cnt += res;
            msf = max(msf,res);
        }
    }
    // even though we don't go back through pre, we can still compute it's component size by subtracting
    // the component size of curr (including itself) from N
    msf = max(msf,N-cnt-1);
    // update answer
    min_com = min(min_com,msf);
    return cnt+1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b),g[b].push_back(a);
        ind[a] += 1,ind[b] += 1;
    }
    // it can begin anywhere, but the starting node will just get a sum component size of N
    dfs(1,0);
    cout << min_com << '\n';
    return 0;
}