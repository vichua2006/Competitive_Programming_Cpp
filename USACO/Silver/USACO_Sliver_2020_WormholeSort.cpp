// (DSU) cow ci can return to i as long as it belongs in the same component as i for all i
// sort edges from wide to narrow, then add them one at a time until the previous statement becomes true

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

int n,m,l[100001],cow[100001];
pair<int,pair<int,int>> e[100000];

int find(int x){
    while(x != l[x]) x = l[x];
    return x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);

    cin >> n >> m;
    for (int i=0;i<n+1;i++)l[i] = i;
    for (int i=1;i<n+1;i++) cin >> cow[i];
    for (int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        e[i] = {-c,{a,b}};
    }
    sort(e,e+m);
    int idx = 0, w = INF;
    for (int i=1;i<n+1;i++){
        if (cow[i] == i) continue;
        while(find(i) != find(cow[i])){
            int a,b,c;c = e[idx].first,a = e[idx].second.first, b = e[idx].second.second;
            a = find(a); b = find(b);
            if (a == b) continue;
            if (a < b) swap(a,b);
            l[b] = a;
            idx += 1;
            w = min(w,+abs(c));
        }
    }
    if (w == INF) w = -1;
    cout << w << '\n';
    return 0;
}