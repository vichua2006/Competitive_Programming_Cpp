/*

uses array to simulate a (static) single linked list
this is faster than initializing new structs during the excution of the program (using struct Node(){...})
https://www.acwing.com/video/253/

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int M;
// head: ptr (the index) of the first node. idx: ptr pointing two the next available array space for new node 
int head, idx;
// e[i] is the value of the ith node, and ne[i] is the next of the ith node
int e[maxN], ne[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void init(){
    head = -1;
    idx = 0;
}

// insert a new node as the head node
void addh(int x){
    // 1. sets value for the new node
    // 2. point the new node to the previous head node
    // 3. set the new node as the current head node
    // 4. increment idx
    e[idx] = x, ne[idx] = head, head = idx, idx += 1;
}

// add a new node behind the node with index k
void addb(int k, int x){
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx, idx += 1;
}

// remove the node behind the node with index k
void removeb(int k){
    // points the next of node to two nodes after it (and thus skips the removed node)
    // this method of removal is particularly bad in the sense that it does not free up the memory used by the removed node (idx is not adjusted)
    // however, this is competitive programming, so all is good. 
    ne[k] = ne[ne[k]];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    init();

    cin >> M;
    while (M--){
        int x, k;
        char c;

        cin >> c;
        if (c == 'H'){
            cin >> x;
            addh(x);
        }
        if (c == 'D'){
            cin >> k;
            // if k == 0, it is stated that it meant the removal of the head node
            if (!k) head = ne[head];
            else removeb(k - 1);
        }
        if (c == 'I'){
            cin >> k >> x;
            // the index here is k - 1 because that would be the kth inserted node (since idx started at 0)
            addb(k - 1, x);
        }
    }

    for (int i=head;i!=-1;i=ne[i]) cout << e[i] << ' ';
    return 0;
}