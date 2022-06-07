//tree problem
// theoretically, dis[p1] = 0, dis[p2] = 1,... dis[pk] = k-1 fits the constrains
// we can use this characteristic to construct the tree
// we iterate through p, for each pi, edge[pi] + dis[ancestor(pi)] = i-1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
// b is the tree array, p is the permutation, and dis is the distance[i] of node i to root
// edge[bi] denotes the weight of the edge connecting bi to i (bi's ancestor) 
int N,b[maxN],p[maxN],dis[maxN],edge[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int t=0;t<N;t++){
        int n; cin >> n;
        // 1 indexed array for convienence
        for (int i=1;i<n+1;i++) cin >> b[i];
        for (int i=1;i<n+1;i++) cin >> p[i];
        // dis needs to be initialized
        memset(dis,-1,sizeof(dis)), memset(edge,0,sizeof(edge));
        // find root of tree
        int r;
        for (int i=1;i<n+1;i++){
            if (b[i] == i){
                r = i;
                break;
            }
        }
        // check if root is the first element of p
        if (r != p[1]){
            cout << -1 << '\n';
            continue;
        }
        dis[r] = 0, edge[r] = 0;
        bool valid = true;
        //iterate through p
        for (int i=1;i<n+1;i++){
            int pi = p[i];
            // observation: if a is child of b, then dis[b] < dis[a] since all weigths are positive
            // so if a child is placed before its parent, the permutation is impossible
            // check if child is placed before its parent
            if (dis[b[pi]] == -1){
                valid = false;
                break;
            }
            edge[pi] = i-1-dis[b[pi]];
            dis[pi] = i-1;
        }
        if (!valid) cout << -1 << '\n';
        else{
            for (int i=1;i<n+1;i++) cout << edge[i] << (i == n?'\n':' ');
        }
    }
    return 0;
}