/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 10, INF = 1e9, MOD = 1e9 + 7;
ll N, ave;
ll arr[maxN], needs[maxN];
vector<ll> g[maxN];
vector<ar<ll, 3>> operations;

void qry(int curr, int pre){
    for (int a: g[curr]){
        if (a ==  pre) continue;
        qry(a, curr);
        needs[curr] += needs[a];
    }

    needs[curr] += arr[curr] - ave;
}

void red(int curr, int pre){
    vector<int> pos, neg;
    for (int a : g[curr]){
        if (a == pre) continue;
        if (needs[a] >= 0) pos.push_back(a);
        else neg.push_back(a); 
    }

    // adds all excess onto 
    for (int p : pos) red(p, curr);
    // redistribute all excess onto nodes that need them
    for (int n : neg){
        // cout << curr << ' ' << n << ' ' << abs(needs[n]) << '\n';
        operations.push_back({curr, n, abs(needs[n])});
        red(n, curr);
    }

    // sends any excess back to parent
    if (needs[curr] > 0){
        // cout << curr << ' ' << pre << ' ' << arr[curr] - ave << '\n';
        operations.push_back({curr, pre, needs[curr]});
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    ll sum = 0;
    for (int i=1;i<N+1;i++) cin >> arr[i], sum += arr[i];
    for (int i=1;i<N;i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }

    ave = sum / N;

    qry(1, 0);
    red(1, 0);

    cout << operations.size() << '\n';
    for (auto op : operations) cout << op[0] << ' ' << op[1] << ' ' << op[2] << '\n';

    return 0;
}