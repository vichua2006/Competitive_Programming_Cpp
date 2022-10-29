/*

this is greedy + dp. to think using sets, we are searching the optimal solution in the set of all the 
possilbe ways to choose the stones, which consists to two aspects:

1. the order in which the stones are chosen, and
2. which stones are chosen

suppose the order in which stones are eaten is 

a1, a2, ... , aN

let there be two stones ai and ai+1. consider what would happen if they were swapped in the order

let t be the time we eat the ith stone

before, they would yield a total of 
Ei - t * Li + Ei+1 - (t + Si) *Li+1

and after, they yield
Ei+1 - t * Li+1 + Ei - (t + Si+1) * Li

we want the new solution to be better than the previous, we let us assume 
Ei+1 - t * Li+1 + Ei - (t + Si+1) * Li > Ei - t * Li + Ei+1 - (t + Si) * Li+1

after simplification, we obtain:

Si+1/Li+1 < Si/Li

therefore, it is only optimal to swap i and i + 1 when the above inequality holds true

thus, we should sort the stones by their Si/Li values, which takes care of the first aspect: in which order they are chosen

next, we use knapsack dp to decide which ones to eat (really, all of them are eaten, but it's just that some of the stones 
will be reduced to a energy value of 0, which makes it irrealevent)

it is worth noting that here, dp[i][j] denotes the max value when considering the first i stones and using EXACTLY j seconds
no more than j seconds will not yield the optimal solution, as it may have "empty" time gaps between the items, which will cause
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e4 + 10, INF = 1e9, MOD = 1e9 + 7;
int T, N, M = maxN - 1;
int dp[maxN];
struct Stones{
    int s, e, l;
    bool operator< (const Stones &St){
        return s * St.l < St.s * l;
    }
} stones[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    int C = T;
    while (T -- ){
        cin >> N;
        for (int i=0;i<N;i++){
            int s, e, l; cin >> s >> e >> l;
            stones[i] = {s, e, l};
        }

        sort(stones, stones + N);
        memset(dp, -0x3f, sizeof(dp));

        dp[0] = 0;
        for (int i=0;i<N;i++){
            int s = stones[i].s, e = stones[i].e, l = stones[i].l;
            for (int j=M;j>=s;j--){
                dp[j] = max(dp[j], dp[j - s] + max(0, e - (j - s) * l));
            }
        }   

        int res = -INF;
        for (int i=0;i<M+1;i++) res = max(res, dp[i]);
        cout << "Case #:" << C - T << ' ' << res << '\n';
    }

    return 0;
}