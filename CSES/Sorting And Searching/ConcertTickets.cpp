//Being lazt here, we can use set and upper_bound to find the first element e S.T. e<=ti
// O(nlogn), should pass
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M;
multiset<int> tickets;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        tickets.insert(a);
    }
    for (int i=0;i<M;i++){
        int a; cin >> a;
        // iterator pointing to first element not less than a
        auto it = tickets.upper_bound(a);
        if (it == tickets.begin()) cout << -1 << '\n';
        else{
            it--;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
    return 0;
}