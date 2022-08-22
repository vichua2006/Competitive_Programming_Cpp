/*

greedy, sort the ranges by their right most point and iterate through them
for every range that doesn't contain a point, we pick a point at its
right most point. we sort them by their right most point for this reason
or else situations like:
|----------------------| A
        |--------| B
might occur as we will then pick point A instead of B

to prove that this is correct, let ans be the optimal solution and cnt be 
the solution obtained through this method.

first, since ans is the optimal (and thus minimum, in this case) solution
any other solution, cnt, will be >= ans

1. ans <= cnt

then, since we obtained cnt, this means that there were at least cnt ranges.
and amongst them, there are cnt ranges whoare disjoint with each other
and since 1 point can only cover 1 disjoint range, any solution will need at least cnt points to
cover all the ranges. since ans is a solution, ans >= cnt.

2. ans >= cnt

hence, by 1. && 2., we get that cnt == ans
in other words, our greedy strategy works 100% of the time.
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
ar<int,2> arr[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    // left second, right first
    for (int i=0;i<N;i++) cin >> arr[i][1] >> arr[i][0];
    sort(arr,arr+N);
    // p actually needs to be less than the minimum limit to prevent cases like:
    // 1
    // -1000000000 1
    int cnt = 0,p = -INF-1;
    for (int i=0;i<N;i++){
        int b = arr[i][0],a = arr[i][1];
        if (a<=p&&p<=b) continue;
        else {
            cnt += 1;
            p = b;
        }
    }
    cout << cnt << '\n';
    return 0;
}