// colored graph
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

const int maxN = 1e5+1;

int n,m,color[maxN];
vector<int> g[maxN];

bool solve(int start){
    vector<int> s;
    color[start] = 1;
    s.push_back(start);
    while(!s.empty()){
        int node = s.back(); s.pop_back();
        for (int v:g[node]){
            if (color[v] == 0){
                // alternate the color
                color[v] = color[node] + int(color[node] == 1) - int(color[node] == 2);
                s.push_back(v);
            }
            // if there are same color next to each other
            if (color[v] == color[node]) return false;
            
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    bool flag = true;
    for (int i=1;i<n+1;i++){
        if (color[i] == 0){
            flag = solve(i);
        }
        if (!flag) break;
    }
    if (flag){
        for (int i=1;i<n+1;i++){
            cout << color[i] << ' ';
        }
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}