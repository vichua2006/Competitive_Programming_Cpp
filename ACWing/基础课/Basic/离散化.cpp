/*

this is classic problem of index compression

the obvious way to do this problem is to fit all of the numbers into a prefix sum array. However, the range of the numbers (-1e9 ~ 1e9) is too large
so we must compress the index before placing them into the array. This can be done with sorting and a hash map.
the query can be done using binary search to find the corresponding index in O(logn) and computed in O(1) with prefix sum

TO get rid of repeating elements:

sort(arr.begin(), arr.end())
arr.erase(unique(arr.begin(), arr.end()), arr.end()) // gets rid of repeating elements
// https://cplusplus.com/reference/algorithm/unique/

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
ll pre[maxN];
vector<ar<ll, 2>> arr;
unordered_map<ll, ll> d;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int find(ll x){
    // standard binary jump
    // this finds the first element that is not less than x
    int p = -1, n = arr.size();
    for (int b=n;b>=1;b/=2){
        while (p + b < n && arr[p + b][0] < x) p += b;
    }
    return p + 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<N;i++){
        ll a, b; cin >> a >> b;
        d[a] += b;
    }
    // pull into a vector
    for (auto a: d) arr.push_back({a.first, a.second});
    sort(arr.begin(), arr.end());
    for (int i=0;i<arr.size();i++){
        // constructing the prefix sum array
        pre[i+1] = pre[i] + arr[i][1];
    }

    for (int i=0;i<M;i++){
        ll a, b; cin >> a >> b;
        int na = find(a);
        int nb = find(b);
        // for cases where the query range goes beyond what is actually mapped
        if (nb >= arr.size()) nb = arr.size() - 1;
        // for cases where p + 1 (the returned value of find) exceeds the upper range specified by b
        if (arr[nb][0] > b) nb -= 1;
        // + 1 to index to adjust to 1-indexing
        cout << pre[nb + 1] - pre[na] << '\n';
    }
    return 0;
}