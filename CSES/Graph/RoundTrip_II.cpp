//cycle in directed graph 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,visited[maxN],p[maxN],ans;
vector<int> g[maxN],cycle;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int solve(int v){
    // since there are no self looping BS, 
    // if a discovered node is once again discovered, 
    // it means we have found a cycle that is guareeteed to have length >= 2
    if (visited[v] == 1) return v;
    if (visited[v] == 2) return 0;
    visited[v] = 1;
    for (int a:g[v]){
        // for each node, record parent node
        p[a] = v;
        int result = solve(a);
        if (result) return result;
    }
    visited[v] = 2;
    return 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i=1;i<N+1;i++){
        if (!visited[i]){
            p[i] = i;
            ans = solve(i);
            if (ans){
                // ans would be where the loop ended
                cycle.push_back(ans);
                int x = p[ans];
                while (ans != x){
                    // trace back to beginning of loop
                    cycle.push_back(x);
                    x = p[x];
                }
                cycle.push_back(ans);
                cout << cycle.size() << '\n';
                for (auto i=cycle.end()-1;i>=cycle.begin();i--) cout << *i << ' ';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}