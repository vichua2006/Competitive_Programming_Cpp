#include<bits/stdc++.h>
// for using ordered set to simulate the process
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

// we have to use another namespace to get the structure
#define gnu __gnu_pbds
#define ordered_set gnu::tree<int,gnu::null_type,std::less<int>,gnu::rb_tree_tag,gnu::tree_order_statistics_node_update>

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,K;
ordered_set ordset;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> K;
    K += 1;
    for (int i=1;i<N+1;i++) ordset.insert(i);
    int p = (K-1)%N;
    while (ordset.size()>1){
        // find the pth element
        auto it = ordset.find_by_order(p);
        cout << *it << ' ';
        // erase it
        ordset.erase(it);
        // because we erase the pth element, p is technically at p+1, so we already
        // moved forward by another step, so -1 is needed.
        p = (p+K-1)%(int)ordset.size();
    }
    cout << *ordset.begin() << '\n';
    return 0;
}