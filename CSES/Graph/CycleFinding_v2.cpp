/*
 
first, determine if there actually exists a negative cycle with spfa (refer to the spfa file in acwing section)
whilst maintaining a parents array

then, using the parents array, loop through all nodes that are a part of the loop

two big mistakes:

1. ensure that the node discovered is actually a part of the loop

2. make sure that the answer is being outputted in the correct order (was outputing in reverse, and that loop does not exist)
 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array
 
const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
ll dis[maxN], cnt[maxN], par[maxN];
bool vis[maxN], inq[maxN];
vector<ar<int, 2>> g[maxN];
 
void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
 
int spfa(int s){
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    inq[s] = 1;
    
    while (q.size()){
        int v = q.front(); q.pop();
        inq[v] = 0;
        for (auto a : g[v]){
            int nc = a[0], nv = a[1];
            if (dis[nv] > dis[v] + nc){
                dis[nv] = dis[v] + nc;
                cnt[nv] = cnt[v] + 1;
                // par[i] denotes the parent node of node i
                par[nv] = v;
                if (cnt[nv] > N){
                    return nv;
                }
                if (!inq[nv]){
                    q.push(nv);
                    inq[nv] = 1;
                }
            }
        }
    }
 
    return 0;
}
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
 
    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({c, b});
    }
 
    memset(dis, 0x3f, sizeof(dis));
    for (int i=1;i<N+1;i++){
        if (dis[i] > 1e13){
            par[i] = -1;
            int res = spfa(i);
            if (res){
                // we backtrack N times to ensure that res is in fact a PART of the negative loop
                // and not just some node that branches off of the loop, because such a node may still be updated
                vector<int> ans;
                for (int i=0;i<N;i++) res = par[res];
                ans.push_back(res);
                for (int i=par[res];i!=res;i=par[i]) ans.push_back(i);
                ans.push_back(res);

                reverse(ans.begin(), ans.end());
                cout << "YES\n";
                for (auto a : ans) cout << a << ' ';
                return 0;
            }
        }
    }
 
    cout << "NO\n";
 
    return 0;
}