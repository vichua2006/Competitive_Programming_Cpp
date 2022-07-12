/*

interesting problem.
obviously, anything higher than O(nlogn) will not pass

any starting position, i, will result in the sum: 
    
    arr[i] + arr[i+1] +...+ arr[j] <= T for the largest j

put that into prefix sum notation, you get:

    pre[j] - pre[i-1] <= T

rearrange into:

    pre[j] <= pre[i-1] + T

so we just need to find the largest j such that pre[j] <= a fixed value (pre[i-1] + T)
since arr[i] > 0 for all i, pre[i] < pre[j] for any i < j
which means that the search j can be done in O(logn) with binary search

the answer is the max of (j - i + 1) for all i

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, T;
ll pre[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> T;
    for (int i=1;i<N+1;i++) cin >> pre[i], pre[i] += pre[i-1];
    int res = 0;
    for (int i=1;i<N+1;i++){
        ll tar = (ll)T + pre[i-1];
        // start at the every beginning, not even at 1 but at 0, as it can create the case where it includes the first element but it was not supposed to
        int p = 0;
        for (int b=N;b>=1;b/=2){
            while (p + b <= N && pre[p + b] <= tar) p += b;
        }
        res = max(res, p - i + 1);
    }
    cout << res << '\n';
    return 0;
}