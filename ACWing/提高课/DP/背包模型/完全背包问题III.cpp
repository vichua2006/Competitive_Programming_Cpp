/*
(rated hard on acwing)


unlike unbounded knapsack, there isn't a an equation that can simplify a loop into a compressed expression

however, when computing dp[i][j], d[i][j - v], dp[i][j - 2v], ..., we see that :

dp[i][j] =      max(dp[i - 1][j], dp[i - 1][j - v] + w, dp[i - 1][j - 2v] + 2w, ... , dp[i - 1][j - sv] + sw)
dp[i][j - v] =  max(dp[i - 1][j - v], dp[i - 1][j - 2v] + w, ... , dp[i - 1][j - sv] + (s - 1)w, dp[i][j - (s + 1)v] + sw)
dp[i][j - 2v] = ...


            *       *       *       ...       *       *       *

(dp[i - 1]) r     r + v    r + 2v           j - 2v   j - v    j

suppose the above is a number line, and let s = 3 for this example
realize that, when computing dp[i][j], it essentially compute the maximum value of the window
from j - 3v to j - v
generally, for any s, when computing dp[i][j]

we are computing the maximum value of a window from j - sv to j - v
this max value can be maintained throught a sliding window (with monotonic queue)

I currently really don't want to write more comments, so just rewatch the acwing video if must
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int dp[maxN], pre[maxN], q[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        int v, w, s; cin >> v >> w >> s;
        // j is the remainder 
        memcpy(pre, dp, sizeof(dp));
        for (int j=0;j<v;j++){
            // head and tail pointer of the queue
            int hh = 0, tt = -1;
            for (int k=j;k<=M;k += v){
                // if queue is not empty and the last element is out of the window
                // inside the queue stores index of the raw values of pre[k], without the w added
                // the w's are then computed added during the comparisons
                // the following expressions:
                // 1. checks if the last element is out of the range of the window 
                // 2. pre[q[hh]] denotes the largest dp[i - 1][k - mv] there is for some m <= s
                //    it's corrisponding w value would equal mw, since q[tt] denotes the index, it equals k - mv
                //    thus, m = (k - q[tt]) / v (whatever the coefficient on v is, that's how many w's there are)
                // 3. this is the monotonic queue logic, but to correctly compare two values in the pre array
                //    the missing w values have to be added on.
                if (hh <= tt && q[hh] < k - s * v) hh ++ ;
                if (hh <= tt) dp[k] = max(dp[k], pre[q[hh]] + (k - q[hh]) / v * w);
                while (hh <= tt && pre[q[tt]] + (k - q[tt]) / v * w <= pre[k]) tt -- ;
                q[ ++ tt] = k;
            }    
        }
    }
    cout << dp[M] << '\n';

    return 0;
}