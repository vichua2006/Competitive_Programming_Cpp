// minimum spanning tree with a twist
// given a tree, you are asked to find the minimum spanning tree closest to the original tree
// since there are n-1 edges to begin with, everytime we activate a pipe, we also need to deactivate one
// note: the algorithm is called Kruskal’s algorithm
//
// 11/15 without considering D

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const ll maxN = 1e6+1;

ll n,m,D,act,l[maxN],s[maxN];
priority_queue<ar<ll,4>,vector<ar<ll,4>>,greater<ar<ll,4>>> pq;

ll find(ll x){
    while (l[x] != x) x = l[x];
    return x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> D;
    for (int i=1;i<n+1;i++){
        // standard DSU procedure
        s[i] = 1;
        l[i] = i;
    }
    for (int i=0;i<n-1;i++){
        // the first n-1 pipes take priority
        // pq is set to greater, therefore non decreasing ordering, so a 0 takes more priority than 1
        ll a,b,c; cin >> a >> b >> c;
        pq.push({c,0,a,b});
    }
    for (int i=n-1;i<m;i++){
        ll a,b,c; cin >> a >> b >> c;
        pq.push({c,1,a,b});
    }
    while(pq.size()){
        ar<ll,4> u = pq.top();
        pq.pop();
        ll c = u[0],t = u[1],a = u[2],b = u[3];
        a = find(a);
        b = find(b);
        if (a != b){
            if (s[a] < s[b]) swap(a,b);
            l[b] = a;
            s[a] += s[b];
            // if t=0, pip wasn't changed, if t=1, it took one day
            act += t;
        }
    }
    cout << act << '\n';
    return 0;
}