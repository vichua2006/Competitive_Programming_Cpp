//disjoint set union

//this is appearently a graph specific (probably has other usage) 
//data structure use to determine wither two nodes are connected within a graph
//when union, always connect the SMALLER set tot the LARGER set, as it keeps the depth of the tree as short as possible
//thus reducing the time complexity of find()
#include <bits/stdc++.h>
using namespace std;

#define ll long long
//link[i] stores the parent of node i and i if it is the representitive
//size[i] stores the size of set with i as representitive
int link[200001],size[200001],n,q;

int find(int x){
    // finds representitive of x
    while(x != link[x]){
        x = link[x];
    }
    return x;
}

void join_rep(int a,int b){
    // can't use union due to key word??
    // A ∪ B with TC of O(logn)
    a = find(a);b = find(b);
    if (size[a] < size[b]) swap(a,b);
    link[b] = a;
    size[a] += size[b]; 
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;

    //no edges, and each set is size one
    for (int i=0;i<n+1;i++) link[i] = i;
    for (int i=0;i<n+1;i++) size[i] = 1;

    for (int qq=0;qq<q;qq++){
        int a,b,c; cin >> a >> b >> c;
        if (a){
            cout << (find(b) == find(c)) << '\n';
        }
        else{
            join_rep(b,c);
        }
    }
    return 0;
}