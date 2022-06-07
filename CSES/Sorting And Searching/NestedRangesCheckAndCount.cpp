/*
sort and index compress the ranges using index compression

for each range [a,b]:

    when we encounter range i for the fisr time, we know that it is starting.
    to know how many ranges contain range i, we check how many right indices >= b
    are activated. 
    we can set the activated index to 1, and use a segmented tree to sum the interval [b,END]
    with index compression. Thus, we update the answer, and set the value of tree1[b] to 1

    when we encounter range i for a second time, we know that it has ended
    to find out how many ranges is contained in [a,b], we can (the finished ranges have
    their left index set to 1 in tree2) sum the interval [a,b]


due to annoying indexing, can't pass cases like
2
1 13
12 13

because there are two 13s
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,K=1;
int cr[maxN],rc[maxN];
bool act[maxN];
vector<ar<int,2>> arr;
vector<int> tree1,tree2;
// maps range number to the compressed index of left and right
unordered_map<int,ar<int,2>> d;

int qry(int a, int b, vector<int> &tree){
    a += (K-1), b += (K-1);
    int res = 0;
    while (a <= b){
        if (a%2==1) res += tree[a++];
        if (b%2==0) res += tree[b--];
        a /= 2, b /= 2;
    }
    return res;
}

void upd(int p, int k, vector<int> &tree){
    p += (K-1);
    tree[p] += k;
    for (p/=2;p>=1;p/=2) tree[p] = tree[2*p] + tree[2*p+1];
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++){
        int a,b; cin >> a >> b;
        arr.push_back({a,i}), arr.push_back({b,i});
    }
    sort(arr.begin(),arr.end());
    // so that the same position will result in the same compressed index
    int prepos = -1, preidx = -1;
    for (int i=0;i<2*N;i++){
        int a = arr[i][0], b = arr[i][1], p;
        // check if this is the left or right index
        if (d.count(b)) p = 1;
        else p = 0;
        if (prepos==a) d[b][p] = preidx;
        else{
            d[b][p] = i+1;
            prepos = a, preidx = i+1;
        }
    }
    while (K < 2*N) K *= 2;
    tree1.resize(2*K,0), tree2.resize(2*K,0);
    for (int i=0;i<2*N;i++){
        int a = arr[i][0], b = arr[i][1];
        int l = d[b][0], r = d[b][1];
        if (!act[b]){
            cr[b] = qry(r,2*N,tree1);
            upd(r,1,tree1);
            act[b] = 1;
        } else {
            rc[b] = qry(l,r,tree2);
            upd(l,1,tree2),upd(r,-1,tree1);
            act[b] = 0;
        }
    }
    for (int i=1;i<N+1;i++) cout << rc[i] << ' ';
    cout << '\n';
    for (int i=1;i<N+1;i++) cout << cr[i] << ' ';
    return 0;
}