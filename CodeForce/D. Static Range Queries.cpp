/*

if the range of the updates and queries were less than 1e6, than this is merely just a difference and prefix array implementation

however, the ranges can be compressed, which will achieve a similar effect and allow the usage of difference and prefix array
there are at most 4e5 distinct indices that will be used.

because updating with (a, b) only updates [a, b)
between two consecutive indices, l and r, all cells between the range [l, r) will have the same value (think this out).
suppose l was the ith index, and r was the i + 1 index. then the interval [l, r) is the ith interval, and all values between are the same

thus, we can let dif[i] denote, instead of the difference between the i and i - 1 cell, the difference between the values of the ith and i-1 interval
and to calculate the sum of a interval, we take the length of that interval (r - l) and multiply it by that value

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 4e5 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, Q;
// the difference, actual, prefix arrays, and length for the intervals
ll dif[maxN], arr[maxN], pre[maxN], len[maxN];
vector<int> indices;
vector<ar<int, 2>> qry;
vector<ar<int, 3>> upd;

int getCompressedIndex(int x){
    // lower bound returns a iterator pointing to the first element that is at least x
    return lower_bound(indices.begin(), indices.end(), x) - indices.begin();
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=0;i<N;i++){
        int a, b, c; cin >> a >> b >> c;
        indices.push_back(a), indices.push_back(b);
        upd.push_back({a, b, c});
    }
    for (int i=0;i<Q;i++){
        int a, b; cin >> a >> b;
        indices.push_back(a), indices.push_back(b);
        qry.push_back({a, b});
    }

    sort(indices.begin(), indices.end());
    // unique shifts all the repearing elements to the back of the container to be overwritten, and returns 
    // a iterator pointing to the new "end" of the container, or the first repeated element
    // [10, 10, 20, 30, 30] -> [10, 20, 30, ?, ?]
    //                                      ^
    indices.erase(unique(indices.begin(), indices.end()), indices.end());
    // these two lines give us a sorted vector without duplicates.

    for (int i=0;i<indices.size()-1;i++){
        // switches to 1-indexed
        len[i + 1] = indices[i + 1] - indices[i];
    }

    for (auto a : upd){
        int l = a[0], r = a[1], v = a[2];
        // intervals from i to j - 1, so dif[i] + v, dif[j] - v
        // using 1-indexed for convienence
        dif[getCompressedIndex(l) + 1] += v;
        dif[getCompressedIndex(r) + 1] -= v;
    }

    // compute actual values of interval i
    for (int i=1;i<indices.size();i++) arr[i] = dif[i] + arr[i - 1];
    // compute the prefix sum of intervals
    for (int i = 1; i < indices.size(); i ++ ) pre[i] += pre[i - 1] + arr[i] * len[i];

    // answer the queries
    for (int i = 0; i < Q; i ++ ){
        int a = qry[i][0], b = qry[i][1];
        // getCompresssedIndex returns the 0-indexed value, which is 1 less than the desired value
        // here, since it asks the of [l, r), its pre[r - 1] - pre[l - 1]
        // which is r and l, in 0-index form, which works out
        cout << pre[getCompressedIndex(b)] - pre[getCompressedIndex(a)] << '\n';
    }

    return 0;
}