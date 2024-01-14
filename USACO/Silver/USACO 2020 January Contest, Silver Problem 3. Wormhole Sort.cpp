/*

"find the minimum of x"
when x is not distance, consider binary search

binary search the minimum width of the wormhole, let it be k. 

connect all nodes that are connected by a wormhole that has width that
is greater than or equal to k. this can be done with dfs or dsu

cow i will be able to sort itself if and only if pi and i are connected
in other words, they belong in the same component
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int l[maxN], cow_pos[maxN];
vector<int> w;
vector<ar<int, 3>> edges;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int find(int x){
    if (x != l[x]) l[x] = find(l[x]);
    return l[x];
}

bool check(int k){
    // checking done with dsu
    for (int i=1;i<N+1;i++) l[i] = i;

    for (auto e : edges){
        int c = e[0], a = e[1], b = e[2];
        if (c < k) continue;
        a = find(a), b = find(b);
        if (a != b) l[a] = b;
    }

    for (int i=1;i<N+1;i++){
        if (find(i) != find(cow_pos[i])) return 0;
    }

    return 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("wormsort");

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> cow_pos[i];

    // check if cows are already sorted
    if (check(0)){
        cout << -1 << '\n';
        return 0;
    }

    for (int i=0;i<M;i++){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({c, a, b});
        w.push_back(c);
    }

    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());

    // binary searching the possible widths instead of the range [1, 1e9]
    // and since it's not an actual number but an index, binary jump instead
    int p = 0;
    for (int b=M-1;b;b/=2){
        while (p + b < M && (!check(w[p + b]))) p += b;
    }

    cout << w[p + 1] << '\n';
    return 0;
}