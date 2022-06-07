// basically, given an array of integers, and value k, find the first element that is greater than or equal to k
// then update the element (subtract k), and print the position of the element
// this requires, instead of traversing a segmented tree bottom-up, we have to go from top to bottom
// each node will store the max value of that segment, so we just keep going down the leftmost path with value A >= k
// time complexity O(logN + 2QlogN)
// see CPH range queries section for more detail
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,Q,K=1;
vector<int> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void compute_tree(int r){
    if (r >= K) return;
    compute_tree(2*r),compute_tree(2*r + 1);
    tree[r] = max(tree[2*r],tree[2*r + 1]);
    return;
}

int find_value(int h){
    // returns the position of the first value that is greater than h
    // if such a position doesn't exist
    if (h > tree[1]) return 0;
    int pos = 1;
    while (pos < K){
        if (tree[2*pos] >= h) pos = 2*pos;
        else pos = 2*pos + 1;
    }
    return pos;
}

void update_tree(int p, int v){
    // subtract the value at position p by v, then recompute the tree
    p += K-1;
    tree[p] -= v;
    for (p/=2;p>=1;p/=2) tree[p] = max(tree[2*p],tree[2*p + 1]);
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    while (K < N) K = K<<1;
    // construct segmented tree
    tree.resize(2*K);
    for (int i=0;i<N;i++) cin >> tree[i+K];
    compute_tree(1);
    for (int i=0;i<Q;i++){
        int rooms; cin >> rooms;
        int p = find_value(rooms);
        if (p == 0){
            cout << 0 << ' ';
            continue;
        }
        // adjust index back to normal
        p = p-K+1;
        cout << p << ' ';
        update_tree(p,rooms);
    }
    return 0;
}