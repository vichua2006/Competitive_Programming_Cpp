/*

so this problem is an interesting and unexpected application of longest increasing subsequence

let the pair (i, j) denote a edge between a south side city at position i and its matching city at position j on the north side
suppose there are two edges (i, j) and (k, l), and WLOG, let i < k (since their positions are distinct)

realized that the two edges are valid (they do not cross each other) if and only if j < l
put generally, for any valid combination of (a1, b1), (a2, b2),..., (ak, bk) where a1 < a2 ... < ak, it must satisfy
b1 < b2 < b3 <...< bk
in other words, each valid combination corresponds to a increasing subsequence in b,

similarly, for each increasing subsequence in b, it corresponds to a valid combination (a1, b1), (a2, b2),..., (ak, bk)
(this is true under the assumption that a1 < a2 <...< ak, which can be done by sorting a)

and notice that the length of the increasing subsequence equals the number of edges

hence, for the most edges that can be selected, we need to find the longest increasing subsequence in b

this mapping/idenctical transformation can only be done after observing the properties brought on by the problem conditions, 
thus, make more observations of each problem before assuming a solution

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e3 + 10,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN], dp[maxN];
ar<int, 2> city[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> city[i][0] >> city[i][1];
    sort(city, city + N);

    for (int i=0;i<N;i++) arr[i + 1] = city[i][1];
    
    int msf = 0;
    for (int i=1;i<N+1;i++){
        dp[i] = 1;
        for (int j=1;j<i;j++){
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
        }

        msf = max(msf, dp[i]);
    }

    cout << msf << '\n';

    return 0;
}