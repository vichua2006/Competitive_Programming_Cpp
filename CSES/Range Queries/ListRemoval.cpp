//Keep a visited array, if the ith element is delete, vistited[i] = false, else true
// by summing that array, we know how many elements are currently present
// to delete the ith element, first check if the number on the root is greater than i
// if so, we then walk down the tree
// suppose from some node, its left child's section has x elements and its right child has y elements
// if x >= i, means that there are at least i elements in the section of its left child, we continue down
// if x < i, we have to go down to the right child section because there aren't enough elements in the left
// since we are looking for the ith element, and there's already x in the first section,
// so we now look for element i-x starting in the second section (which is the equilvalent of element i).
// Hence, we have to subtract i by x, then go down the right child
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,Q,K=1,arr[maxN];
vector<int> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void compute_tree(int r){
    if (r >= K) return;
    compute_tree(2*r),compute_tree(2*r + 1);
    tree[r] = tree[2*r] + tree[2*r + 1];
    return;
}

int find_element(int a){
    int p = 1;
    if (a > tree[1]) return 0;
    while(p<K){
        if (tree[2*p] >= a){
            p = 2*p;
        }
        else{
            // we are now looking for the i-xth element in the second section
            a -= tree[2*p];
            p = 2*p + 1;
        }
    }
    return p-K+1;
}

void update_tree(int p){
    p += (K-1);
    tree[p] = 0;
    for (p/=2;p>=1;p/=2){
        tree[p] = tree[2*p] + tree[2*p+1];
    }
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    while(K<N) K <<= 1;
    tree.resize(2*K,0);
    for (int i=0;i<N;i++){
        int a; cin >> a;
        arr[i+1] = a;
        tree[i+K] = 1;
    }
    compute_tree(1);
    for (int i=0;i<N;i++){
        int a; cin >> a;
        int p = find_element(a);
        cout << arr[p] << (i == N-1?'\n':' ');
        update_tree(p);
    }
    return 0;
}