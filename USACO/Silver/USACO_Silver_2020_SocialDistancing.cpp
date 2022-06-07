//uses binary search on D to reduce O(n^2) to O(n logn)
#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> intervals[100000];
int n,m;

bool solve(long long d){
    //                   -place all n cows, returns if all cows fit or not
    long long maxb = intervals[m-1].second,prepos = intervals[0].first-d,newpos;
    int curr_interval = 0;
    for (int i=0;i<n;i++){
        newpos = prepos + d;
        if (newpos > maxb) return false;
        if (newpos > intervals[curr_interval].second){
            while (newpos > intervals[curr_interval].second){
            curr_interval += 1;
            }
            //           -ensure that new pos is d units away from previous cow
            newpos = max(intervals[curr_interval].first,newpos);
        }
        prepos = newpos;
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);

    cin >> n >> m;
    long long a,b;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        intervals[i] = {a,b};
    }
    sort(intervals,intervals+m);
    long long upper = 1e18, lower = 0, mid = 0,res = -1;
    //                      -binary search the correct distance
    while (lower <= upper){
        mid = lower + (upper - lower)/2;
        if (solve(mid)){lower = mid+1; res = mid;}
        else upper = mid-1;
    }
    cout << res << '\n';

    return 0;
}