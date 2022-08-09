/*

the brute force of this problem would require O(N^3) time 

however, since their heights are unique, for any valid pairs i < j, their heights can create only two cases:

1. hi > hj, or
2. hi < hj

for case one, notice that it means cow i must be the closest cow to the left of j that is taller than hj
if cow i is any further away, it would contradict the assumption that the pair (i, j) is valid (max(hi+1, ..., hj-1) < min(hi, hj))
hence, to find all possible case 1., we iterate, and for each element, find the first element to its left that is greater than the current element 
(or, the index of such element, in this case)

this can be accomplished in O(N) with a monotonic stack

the same logic can be applied to case two, but since they are symmetric, we can simply reverse the cows and go through it again

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll solve(){
    // the stack will store the index and not the actual height of the cows
    vector<int> stk;
    ll res = 0;
    for (int i=0;i<N;i++){
        // if there exist (x, y) such that:
        // 1. a[x] < a[y], and
        // 2. x < y
        // then a[x] can be effectively deleted
        // for detail, refer to the monotonic stack problem in the ACWing DS section
        while (stk.size() > 0 && arr[stk.back()] < arr[i]) stk.pop_back();
        if (!stk.empty()){
            res += (ll) i - stk.back() + 1;
            // cout << stk.back() << ' ' << i << '\n';
        }
        stk.push_back(i);
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i];
    ll ans1, ans2;
    ans1 = solve();
    reverse(arr, arr + N);
    ans2 = solve();
    cout << ans1 + ans2 << '\n';
    return 0;
}