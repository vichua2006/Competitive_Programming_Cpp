/*

another meet in the middle problem
40 instructions, splitting them in half, then piecing the results back together

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array
#define P ar<ll, 2>

// define + - operator for ar<int,2>
P operator+(P a, P b){ return {a[0] + b[0], a[1] + b[1]}; }
P operator-(P a, P b){ return {a[0] - b[0], a[1] - b[1]}; }

const int maxN = 40 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N;
ll ans[maxN];
P G;
vector<P> itr;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

// const is nice habit, because no actual values are supposed to be changed
vector<pair<P, int>> all_subset(const vector<P> &vtr){
    vector<pair<P, int>> v;
    for (int i=0;i<(1<<vtr.size());i++){
        P curr{0, 0};
        int cnt = 0;
        for (int j=0;j<vtr.size();j++){
            // directly add together due to operator
            if (i>>j&1) curr = curr + vtr[j], cnt += 1; 
        }
        v.push_back({curr, cnt});
    }
    return v;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> G[0] >> G[1];
    // read all instructions
    itr.resize(N);
    for (auto &a : itr) cin >> a[0] >> a[1];
    // iterate subsets
    // the parameter can be passed in without being defined with a name when:
    // 1. the parameter is not defined as an reference (because it would not be able to find anything to reference)
    // 2. it is set as a const reference (why ?)
    vector<pair<P, int>> sub1 = 
        all_subset(vector<P>(itr.begin(), itr.begin() + N / 2));
    vector<pair<P, int>> sub2 = 
        all_subset(vector<P>(itr.begin() + N / 2, itr.end()));
    sort(sub1.begin(), sub1.end());
    sort(sub2.begin(), sub2.end());
    reverse(sub2.begin(), sub2.end());
    // two pointer 
    // pointer
    int ib = 0;
    // previous element
    P pre{(ll)1e18, (ll)1e18};
    // for storing temp. results
    vector<ll> sum;
    for (auto &a : sub1){
        P tar = G-a.first;
        // check if the curr lement is the same as the last
        if (tar != pre){
            pre = tar;
            sum = vector<ll>(N, 0);
            // increment pointer until target element
            for ( ; ib < sub2.size() && sub2[ib].first > tar; ib++);
            // count number of target element
            for ( ; ib < sub2.size() && sub2[ib].first == tar; ib++) sum[sub2[ib].second] += 1;
        }
        // this method of two pointers ensures that no elements are missed
        // since ib cannot go back, the regular method would have suffered had there
        // been multiple of the same element in sub1.
        // however, by storing temp. results in sum, we can simply recalculate the answer should that situation occur.
        for (int i=0;i<sum.size();i++) ans[i + a.second] += sum[i];
    }
    for (int i=1;i<N+1;i++) cout << ans[i] << '\n';
    return 0;
}