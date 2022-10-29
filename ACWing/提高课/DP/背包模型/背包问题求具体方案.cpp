/*

my old solution, for a small N and M, was to store a rec[i][j] where
it stored a binary number denoting the items that were and were not picked. This only works for small data
and can't expand to most of the other kinds of knapsack

the general solution is just to trace back with the final answer

since dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - s] + v), if the final answer

dp[N][M] equaled dp[N - 1][M - sN] + vN, then it means that the Nth item must be a part of the optimial solution
with recursive thinking, we are now looking for the items that make up dp[N - 1][M - sN], and thus we check 
dp[N - 2][M - sN - s(N - 1)] + v(N - 1)
...

and so on. check every i from N to 1, and reduce the size if the ith item was picked

UPDATE

now after carefully examining the problem again, it actually requires you to output the lexicographcially smallest solution

appearently, when these statements are made, they are not *purposely* making the problem harder, but just making the judging
of the problem easier, and 90% of the time (stat from yxc), they can be obtained using greedy methods 

we can first consider the first item, and see if it is a part of the items that make up the optimal solution
if it is, then we must select it to creat the lexicographically least solution. we then consider the next item, and so on.

however, in the current order that the items are processed, we can only check the items in reverse order.
thus, in order to check the items in the correct order, we need to reverse the order in which we process

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int s[maxN], v[maxN];
int dp[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) cin >> s[i] >> v[i];

    reverse(s + 1, s + N + 1), reverse(v + 1, v + N + 1);
    for (int i=1;i<N+1;i++){
        for (int j=s[i];j<M+1;j++){
            dp[i][j] = dp[i - 1][j];
            if (j >= s[i])
                // forgot how to write 2-d knapsack
                dp[i][j] = max(dp[i][j], dp[i - 1][j - s[i]] + v[i]);
        }
    }

    int j = M;
    for (int i=N;i;i--){
        // in this case, even if d[i - 1][j] = dp[i - 1][j - s] + v, we still choose the item, as
        // it creats a lexicographically smaller solution
        if (j >= s[i] && dp[i][j] == dp[i - 1][j - s[i]] + v[i]){
            j -= s[i];
            cout << N - i + 1 << ' ';            
        }
    }


    return 0;
}