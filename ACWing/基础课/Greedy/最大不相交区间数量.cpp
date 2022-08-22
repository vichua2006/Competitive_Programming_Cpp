/*

the classic "events" problem, but just worded more formally

we always pick the event that ends the soonest to attend, because it would only increase the solution


proof is similar to picking the minimum number of point on the interval so that 
every range contains a point

let ans be the optimal solution and let cnt be the solution that was obtained by this algorithm

and since we got cnt, that means that there is at least cnt disjoint ranges, which means that the optimal answer
ans must have at least this many ranges, and thus:

1. cnt <= ans

and by choosing this way, it means that these cnt disjoint ranges overlap all other ranges in some way.

now, suppose ans > cnt. That means that there are ans disjoint ranges. However, since the previous
cnt ranges already overlaped all the ranges, there cannot possibly exist ans - cnt ranges that were not
overlaped. Hence, contradiction and thus,

2. ans <= cnt

by 1. and 2. ans == cnt, which means this algorithm is correct. 

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
ar<int, 2> arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool comp(ar<int, 2> &a, ar<int, 2> &b){
    if (a[1] == b[1]) return a[0] < b[0];
    else return a[1] < b[1];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i][0] >> arr[i][1];
    sort(arr, arr + N, comp);

    int cnt = 0, p = -INF - 1;
    for (int i=0;i<N;i++){
        if (p < arr[i][0]){
            cnt += 1;
            p = arr[i][1];
        }

        // cout << arr[i][0] << ' ' << arr[i][1] << '\n';
    }

    cout << cnt << '\n';

    return 0;
}