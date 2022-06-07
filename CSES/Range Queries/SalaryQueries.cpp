// we sort the elements, and each query a,b we simply find the position of the first element >=a and the position of the first element >= b
// ag, and bg, then the number of poeple who have salary in that range is bg-ag + 1 - 1 (bg is not included)
// for updates, we just keep the orginal array and update it in the multiset, which element specifically doesn't matter
//
// Hmm, I TLE'd, not because of the efficiency of multiset, but the fact that the distance(iter a, iter b) function has a linear complexity
// maybe I should implement binary search on that?
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,Q,arr[maxN];
multiset<int> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=0;i<N;i++){
        cin >> arr[i];
        tree.insert(arr[i]);
    }
    for (int i=0;i<Q;i++){
        char t; cin >> t;
        if (t == '?'){
            int a,b; cin >> a >> b;
            auto ita = tree.lower_bound(a), itb = tree.upper_bound(b);
            int ans = distance(ita,itb);
            cout << ans << '\n';
        }
        else{
            int k,x; cin >> k >> x; k -=1;
            // takes out one of the values of arr[k]; erase(arr[k]) would have erased all arr[k]
            // find returns the specfic iterator.
            tree.erase(tree.find(arr[k]));
            // update, then reinsert it
            arr[k] = x;
            tree.insert(arr[k]);
        }
        
    }
    return 0;
}