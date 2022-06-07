/*

we start with the range [0,M]
with each traffic at position a, the range comtaining a,say [x,y]
is split into [x,a] and [a,y].
to quickly find the range that contains a, we binary search it
and we also keep tract of the lengths in a multiset and updates
it for each new traffic light

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M;
set<ar<int,2>> street;
multiset<int> s;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> M >> N;
    street.insert({0,M});
    s.insert(M);
    for (int i=0;i<N;i++){
        int a; cin >> a;
        // find the range that position a is in
        // the first range beginning greater than a - 1 = 
        // first range that begins with less than or = a, and includes a
        auto it = street.upper_bound({a,a});
        it--;
        ar<int,2> r = *it;
        street.erase(it);
        s.erase(s.find(r[1]-r[0]));
        street.insert({r[0],a}),street.insert({a,r[1]});
        s.insert(a-r[0]),s.insert(r[1]-a);
        auto ptr = s.end();
        cout << *(--ptr) << (i==N-1?'\n':' ');
    }
    return 0;
}