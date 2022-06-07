// calculate all min(a,b) where the length of a,b (b-a+1) is a power of 2
// then to process, min(a,b) = min(min(a,a + k -1),min(b - k + 1,b)), where k is the smallest power of 2 not exceeding b-a+1
//                         starts at a, length of k    starts at b, goes back k-1 units, also length of k
// this splits it into two preprocessed parts. K is the smallest power of 2 not exceeding b-a+1 is to ensure that
// the entire range is covered. 
// this uses a segmented tree to implement
// in the specified implementation, tree[n] is the node, tree[n/2] is its parent, tree[2n] is its left child, tree[2n + 1] is its right child
// See CPH for more detail

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

void compute_tree(int n){
    // computes the subtree with root n
    // checks if it is still a tree node, or is already an array element, in which case, it needs to stop
    if (n >= K) return;
    // computes left and right child (their subtrees)
    compute_tree(2*n), compute_tree(2*n + 1);
    // in this case, we need the minimum value because this is minimum range query. In a sum query, we would record the sum
    tree[n] = min(tree[2*n],tree[2*n + 1]);
    return;
}

int find_min(int a, int b){
    a--,b--;
    a += K, b += K;
    // ajust a,b the right indexes
    int ans = INF;
    while (a <= b){
        // if the index is even, it is a left child, else, a right child
        // a is supposed to be left, b is supposed to be right
        // nodes that do not belong in the higher level gets compared and removed
        if (a%2 == 1) ans = min(ans,tree[a]), a += 1;
        if (b%2 == 0) ans = min(ans,tree[b]), b -= 1;
        // imagine the cells gradually merging together
        // [1][2][3][4][5][6] -> [min(1,2)][min(3,4)][min(5,6)]
        // since 3 !| 2, ans needs to be updated with [min(5,6)] for the process to continue
        // after comparison, it is discarded -> [min(1,2)][min(3,4)] -> [min(min(1,2),min(3,4))] -> [1] which is used to update ans one last time
        a /= 2, b /= 2;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    // find the power of 2 that is >= N, this is for the size of the segmented tree
    while (K < N) K *= 2;
    tree.resize(2*K);
    // starting from index 1,  the first K-1 act as tree nodes, the last K cells contains the actual array
    // here, K will be acting as N since it is now the actual length of tree
    for (int i=0;i<N;i++) cin >> tree[K+i];
    // find all min(a,b) where b-a+1 is a power of two, in other words, computate the first N cells of tree
    compute_tree(1);
    for (int i=0;i<Q;i++){
        int a,b; cin >> a >> b;
        cout << find_min(a,b) << '\n';
    }
    return 0;
}