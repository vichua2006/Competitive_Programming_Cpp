/*

we first sort the ranges by their starting position
then iterate through:

for each range, we check if the range can be placed into a existing group
to do that, we iterate over each group, and check if the maximum right-most point
of the group is larger than the left-most point of the current range (1)
since the ranges are processed in increasing order by left-most point, this guarentees that 
(1) is correct
if not, we just start a new group

now to prove this, suppose ans is the optimal ans, and cnt is the solution we obtain by apllying this
algorithm. the obtained solution is valid, so 

1. ans <= cnt

and when the cnt th group was added, it meant that we iterated through the other cnt-1
groups and found out that they all over lapped with the current range, hence a new group was required
this also means that the cnt-1 groups all have a common interval, so they cannot be grouped together
this means that any solution will require at least cnt groups

2. ans >= cnt

by 1. and 2., ans == cnt

oh and, this is O(n^2), but we can optimize it to O(nlogn) by using a multiset
and just cheking the first (smallest) element each time 

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
ar<int,2> arr[maxN];
// stores the maximum right-most position for each group
multiset<int> g;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i][0] >> arr[i][1];
    sort(arr,arr+N);
    for (int i=0;i<N;i++){
        int a = arr[i][0],b = arr[i][1];
        bool valid = 0;
        // check if the smallest element is larger than a
        if (i==0||*g.begin() >= a) g.insert(b);
        else {
            g.insert(max(*g.begin(),b));
            g.erase(g.begin());
        }
    }
    cout << g.size() << '\n';
    return 0;
}