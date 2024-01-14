/*

double sliding window
scan from left to right
whenever a vertical edge is encountered, scan from top down the vertical strip between the current edge and the previous
and determine the amount of area > T this way

the variable naming in this problem is particularly terrible

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 2e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, T;
ll tint[maxN];
bool actx[maxN], acty[maxN];
ar<ll, 2> y[maxN];
vector<ar<ll, 2>> edges;
multiset<ar<ll, 2>> window;

ll sweep(){
    // compute, the amount off "distance" in the current vertical strip has tint value >= T
    int t = 0, dis = 0, prey = 0;
    for (auto it=window.begin();it!=window.end();it++){
        auto a = *it;
        int curry = a[0], n = a[1];
        if (t >= T) dis += curry - prey;
        if (acty[n]) t -= tint[n], acty[n] = 0;
        else t += tint[n], acty[n] = 1;
        prey = curry;
    }

    return dis;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> T;
    for (int i=1;i<N+1;i++){
        int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        edges.push_back({a, i}), edges.push_back({c, i});
        y[i] = {b, d};
        tint[i] = e;
    }
    sort(edges.begin(), edges.end());

    ll area = 0, prex = 0;
    for (int i=0;i<edges.size();i++){
        ll x = edges[i][0], n = edges[i][1];
        // sweep the vertical strip
        area += (x - prex) * sweep();
        if (actx[n]){
            // erase the two y values from the window
            window.erase(window.find({y[n][0], n}));
            window.erase(window.find({y[n][1], n}));
            actx[n] = 0;
        } else {
            // add the two y values into the window
            window.insert({y[n][0], n});
            window.insert({y[n][1], n});
            actx[n] = 1;
        }
        prex = x;
    }

    cout << area << '\n';

    return 0;
}