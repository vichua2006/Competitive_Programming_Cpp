/*

heap, basically heap sorting for this problem

a head is an binary tree whose length does not need to be a power of 2
the cp implementation of heap uses an array, and for this problem, it is defined as such

tree[1] is the root node, and is also the smallest node
for any node tree[x], its left child is tree[2*x] and right child is tree[2*x + 1]

and, tree[x] >= max(tree[2*x], tree[2*x + 1])

two operations are supported: up(x) and down(x), which means adjusting node x up or down the tree,
depending on the value of the node

the solution to this particular problem is to fit all the entire array into a heap, and then query and delete the top node (smallest)
for m times

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
vector<int> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void down(int u, int s){
    // pushes node u down the tree of size s until it satisfies the inequalities
    int t = u;
    // check if left/right child exists and check their respective sizes
    // we also need to check which of the two children is smaller, but by using the dummy variable t,
    // we bypass the need to write if else
    if (2*u <= s && tree[2*t] < tree[t]) t = 2*u;
    if (2*u + 1 <=s && tree[2*u + 1] < tree[t]) t = 2*u + 1;
    // if one of the inequalities didn't hold
    if (u != t){
        // swap the two values
        swap(tree[u], tree[t]);
        // down the new position again
        down(t, s);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    // the tree will be 1-indexed
    tree.resize(N + 1);
    int size = N;
    for (int i=1;i<N+1;i++) cin >> tree[i];

    // here's an interesting way to initialize the heap:
    // https://www.acwing.com/video/263/ (around the 30 min mark)
    for (int i = N/2; i >= 1; i--) down(i, size);

    while (M --){
        cout << tree[1] << ' ';
        // overwrite the top node with the last, then sort it to place
        tree[1] = tree[size --]; down(1, size);
    }
    return 0;
}