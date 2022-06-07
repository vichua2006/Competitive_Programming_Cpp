#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

const int maxN = 1e5+1;

int n,m,visited[maxN];
vector<int> g[maxN],p;

bool solve(int curr, int k){
    // basically, we need to find cycles that have length >= 3
    // store path, when found, trace path and print it.
    if (visited[curr] && k-visited[curr] >= 3){
        p.push_back(curr);
        return true;
    }
    if (visited[curr]) return false;
    visited[curr] = k;
    p.push_back(curr);
    for (int v:g[curr]){
        if (solve(v,k+1)) return true;
    }
    p.pop_back();
    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<n+1;i++){
        // there might be many components, so we need to search all of them
        if (solve(i,1)){
            int temp = p.size()-3;
            while(p[temp]!=p.back()){
                temp -= 1;
            }
            cout << p.size()-temp << '\n';
            for (int i=temp;i<p.size();i++){
                cout << p[i] << ' ';
            }
            return 0;
        }
        p.clear();
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
