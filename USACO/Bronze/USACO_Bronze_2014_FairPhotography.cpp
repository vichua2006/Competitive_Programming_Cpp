/*

3 cases:

1. all 'G'
2. all 'H'
3. equal amounts of both

(we first sort the cows by increasing position)
1. and 2. are easy enough, just iterate through and record size of each chunk

for 3., suppose we set 'G' with a weight of 1 and 'H' with a weight of -1
then, an interval with equal amounts of both would have a sum of 0

since we are querying range sum, we should pre-compute a prefix sum array
and for some position i, we look for the smallest index j such that

pre[i] - pre[j-1] = 0 --> pre[i] = pre[j-1]

which means that there's an equal amount of H and G in the range [j,i]
so we can record the first position at which the value pre[i] = pre[j-1] appears with a 
hash map
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int pre[maxN];
ar<int,2> arr[maxN];
unordered_map<int,int> d;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++){
        int a; cin >> a;
        char t; cin >> t;
        arr[i] = {a,(t=='H'?1:-1)};
    }
    sort(arr+1,arr+N+1);
    int res = 0,sum = 0,last;
    for (int i=1;i<N+1;i++){
        // dirextly store the position of ith element
        // here, sum is w1 + w2 +...+ w(i-1), so [0,i)
        if (d.count(sum)==0) d[sum] = arr[i][0];
        sum += arr[i][1];
        // here, we check if there's a pre[i] = pre[j-1]
        // if d[sum] stored the j-1th cow's position, we would have to 
        // somehow find the position of the next cow and subtract i_pos by j_pos
        // but because on line 57, we store the position before computing the new sum
        // for any sum = w1 + w2 +...+w(i-1), d[sum] stores the postion of the ith cow, not the i-1th
        // so when we find a sum pre[i] = pre[j-1], we can directly compute the distance i_pos - j_pos
        // because d[pre[j-1]] = j_pos
        if (d.count(sum)) res = max(res,arr[i][0]-d[sum]);

        if (i==1||arr[i][1]!=arr[i-1][1]) last = arr[i][0];
        res = max(res,arr[i][0]-last);
    }
    
    cout << res << '\n';
    return 0;
}