/*

dp version of finding diameter

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
// leaf[x] = maximum dis from node x to any leaf
// maxlen[x] = maximum length of all paths that has x as its highest point
int leaf[maxN], maxlen[maxN];
vector<int> g[maxN];

void dfs(int curr, int pre){
    int far_node = -1; 
    // update leaf[curr]
    for (int a:g[curr]){
        if (a != pre){
            dfs(a, curr);
            if (leaf[curr] < leaf[a] + 1) leaf[curr] = leaf[a] + 1, far_node = a;
        }
    }
    // update maxlen[curr]
    // give default value to maxlen[curr] in case there were no other adjacent nodes
    maxlen[curr] = leaf[curr];
    for (int a:g[curr]){
        if (a != pre && a != far_node) maxlen[curr] = max(maxlen[curr], leaf[curr] + leaf[a] + 1);
    }
    return;
}

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    dfs(1, 0);
    int msf = 0;
    for (int i=1;i<N+1;i++) msf = max(msf, maxlen[i]);
    cout << msf << '\n';
    return 0;
}