/*

binary search for the minimum value x

then for each value x, connect the edges with distance k where k * k <= x
then check connectivity either with dfs or dsu

dsu will be used in this case

time complexity is around O(log(W_max) * N(N - 1) / 2) ~ 1e7

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int l[maxN];
ar<ll, 2> arr[maxN];
vector<ll> w;
vector<ar<ll, 3>> edges;

void IO(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int find(int x){
    if (x != l[x]) l[x] = find(l[x]);
    return l[x];
}

bool connected(ll k){
    for (int i=1;i<N+1;i++) l[i] = i;
    for (auto [c, a, b] : edges){
        if (c > k) continue;
        a = find(a), b = find(b);
        if (a != b) l[a] = b;
    }

    int hh = find(1);
    for (int i=1;i<N+1;i++){
        if (find(i) != hh) return 0;
    }

    return 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    IO("moocast");

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i][0] >> arr[i][1];
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            auto [a, b] = arr[i];
            auto [c, d] = arr[j];
            ll x = abs(a - c), y = abs(b - d);
            ll dis = x * x + y * y;
            edges.push_back({dis, i + 1, j + 1});
            w.push_back(dis);
        }
    }

    sort(w.begin(), w.end());

    // the binary jump will yield the last index before the graph becomes fully connected
    // so the answer is w[p + 1];
    int p = 0;
    for (int b=w.size() - 1;b;b/=2){
        while (p + b < w.size() && (!connected(w[p + b]))) p += b;
    }

    cout << w[p + 1] << '\n';

    return 0;
}