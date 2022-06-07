// standard DSU, first join, then iterate through to check, O((M+N)logN) ~ 3e6
// hell yeah passed first try

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxN = 1e5+1;

int n,m,l[maxN],s[maxN];
vector<pii> edges;

int find(int x){
    while (x != l[x]) x = l[x];
    return x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=1;i<n+1;i++){
        l[i] = i;
        s[i] = 1;
    }
    for (int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        a = find(a); b = find(b);
        if (a != b){
            if (s[a] < s[b]) swap(a,b);
            l[b] = a;
            s[a] += s[b];
        }
    }
    // just use 1 as the dummy node to test whether two components are connected, since is always exists
    // basically, if i is not connected to the component containing 1, connect the two components through DSU, record the edges.
    int ans = 0;
    for (int i=2;i<n+1;i++){
        int a = find(i), b = find(1);
        if (a != b){
            edges.push_back({1,i});
            if (s[a] < s[b]) swap(a,b);
            l[b] = a;
            s[a] += s[b];
            ans += 1;
        }
    }
    cout << ans << '\n';
    for (pii a: edges) cout << a.first << ' ' << a.second << '\n';
    return 0;
}

