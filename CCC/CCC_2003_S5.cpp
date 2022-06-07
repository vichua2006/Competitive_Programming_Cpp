#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
const int maxN = 1e5+1, INF = 1e9;

int c,r,d,ans = INF,l[maxN],cities[maxN];
bool visited[maxN];
vector<pii> g[maxN];
pair<int,pii> arr[maxN];


void dfs(int curr,int w){
    cities[curr] = w;
    for (auto a:g[curr]){
        if (!visited[a.first]){
            visited[a.first] = true;
            dfs(a.first,min(w,a.second));
        }
    }
}

int find(int x){
    while(x != l[x]) x = l[x];
    return x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> c >> r >> d;

    // create maximum spanning tree
    for (int i=1;i<c+1;i++){
        l[i] = i;
    }
    for (int i=0;i<r;i++){
        int x,y,z; cin >> x >> y >> z;
        arr[i] = {z,{x,y}};
    }
    sort(arr,arr+r);
    reverse(arr,arr+r);
    for (int i=0;i<r;i++){
        int x = arr[i].second.first,y = arr[i].second.second,z = arr[i].first;
        if (find(x) != (find(y))){
            x = find(x); y = find(y);
            if (x < y) swap(x,y);
            l[y] = x;
            g[x].push_back({y,z});
            g[y].push_back({x,z});
        }
    }
    // perform dfs on the tree to find the max edge for all vertices
    visited[1] = true;
    dfs(1,INF);
    for (int i=0;i<d;i++){
        int a; cin >> a;
        ans = min(ans,cities[a]);
    }
    cout << ans << '\n';
    return 0;
}