/*

instead of messy casework, include all the used indices in the compressing, so that they could be found via lower_bound
the query indices are included, but doesn't effect the values in the prefix sum, which basically makes them non-existent 
except when they are being searched for

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 3e5 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
ll pre[maxN];
vector<int> indices;
vector<ar<int, 2>> qry;
unordered_map<int, ll> d;

int getCompressedIndex(int x){
    // returns the position just after where x is supposed to be
    return lower_bound(indices.begin(), indices.end(), x) - indices.begin();
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<N;i++){
        int a, b; cin >> a >> b;
        indices.push_back(a);
        d[a] += b;
    }

    for (int i=0;i<M;i++){
        // include all used index in the range so that they can be found easily later,
        // without messy casework
        int a, b; cin >> a >> b;
        qry.push_back({a, b});
        indices.push_back(a), indices.push_back(b);
        // d[a] = 0, d[b] = 0;
    }

    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());

    for (int i=0;i<indices.size();i++) pre[i + 1] += pre[i] + d[indices[i]];

    for (auto a : qry){
        int l = a[0], r = a[1];
        cout << pre[getCompressedIndex(r) + 1] - pre[getCompressedIndex(l)] << '\n';
    }

    return 0;
}