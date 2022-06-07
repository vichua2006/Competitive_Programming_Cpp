// i think this is just a direct application of kruskal's algorithm (contructing a spanning tree) using DSU
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,M,s[maxN],l[maxN],ans = 0,used_edge = 0;
vector<ar<ll,3>> e;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll find_rep(ll x){
    while (l[x] != x) x = l[x];
    return x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        l[i] = i;
        s[i] = 1;
    }
    for (int i=0;i<M;i++){
        int a,b,c; cin >> a >> b >> c;
        e.push_back({c,a,b});
    }
    sort(e.begin(),e.end());
    for (ar<ll,3> v:e){
        ll c = v[0], a= v[1], b = v[2];
        a = find_rep(a), b = find_rep(b);
        if (a != b){
            if (s[a] < s[b]) swap(a,b);
            l[b] = a;
            s[a] += s[b];
            ans += c;
            //used to see if there exists a solution; used_edge should equal N-1
            used_edge += 1;
        } 
    }
    if (used_edge == N-1) cout << ans << '\n';
    else cout << "IMPOSSIBLE\n";
    return 0;
}