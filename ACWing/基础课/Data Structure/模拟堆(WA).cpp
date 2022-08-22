#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
int sz = 0;
ar<int, 2> h[maxN];
// i: current position of the ith inserted element
unordered_map<int, int> d;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void down(int u, int s){
    int t = u;
    if (2*u <= s && h[2*t][0] < h[t][0]) t = 2*u;
    if (2*u + 1 <=s && h[2*u + 1][0] < h[t][0]) t = 2*u + 1;

    if (u != t){
        swap(d[h[u][1]], d[h[t][1]]);
        swap(h[u], h[t]);
        down(t, s);
    }
}

void up(int u, int s){
    // not written recursively for speed; down has two options, which makes it more suitable
    while (u / 2 && h[u / 2][0] > h[u][0]){
        swap(d[h[u][1]], d[h[u / 2][1]]);
        swap(h[u], h[u / 2]);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    // the tree will be 1-indexed
    int cnt = 1;
    while (N --){
        string op;
        int a, b;
        cin >> op;
        if (op == "I"){
            cin >> a;
            h[ ++ sz] = {a, cnt};
            d[cnt] = sz;
            cnt += 1;
            up(sz, sz);
        } else if (op == "PM"){
            cout << h[1][0] << '\n';
        } else if (op == "DM"){
            d[h[sz][1]] = 1;
            h[1] = h[sz -- ];
            down(1, sz);
        } else if (op == "D"){
            cin >> a;
            // adjust the recorded position of the last element, which would be moved up to the deleted element's position
            d[h[sz][1]] = d[a];
            h[d[a]] = h[sz -- ];
            up(d[a], sz), down(d[a], sz);
        } else {
            cin >> a >> b;
            h[d[a]][0] = b;
            up(d[a], sz), down(d[a], sz);
        }
    }
    return 0;
}