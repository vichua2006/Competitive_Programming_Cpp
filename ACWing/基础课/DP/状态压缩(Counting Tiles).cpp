/*

the key concept of this problem is to place all the horizontal blocks first
that way, once all of them are placed, and we check that the arrangement is valid,
the vertical rectangles are left with one method of placement.

let dp[i][k] denote the number of ways to arrange the first i - 1 columns with some rectangles extending into the ith
column in the shape of k, where k is a binary number (10010, for example, denotes the first and second last rows have extended into the ith row)

some k may not form valid configuration. namely, if any continuous group of 0 is not a multiple of 2, then it cannot fill by vertical blocks

lastly, dp[i][k] = dp[i - 1][1] + dp[i - 1][2] +...+ dp[i - 1][l] ...+ dp[i - 1][1 << N - 1].
note that they are only added if the combination of the two configuration is valid. that is to say:
blocks cannot overlap (k & l == 0), and
the i - 1 row (l | k) must have group of 0 that are even

dp[i - 1][l] is only added to dp[i][k] if l satisfies those conditions

thus, since N, M <= 11, the time complexity will amount to 11 * 2^22 = 4e7, which is quite high
and there are multiple test cases

to reduce the runtime, we can precompute all the valid ks and all the valid ls for each k

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 12,maxM = 1 << maxN,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
ll dp[maxN][maxM];
bool val[maxM];
vector<int> vl[maxM];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    N = maxN, M = maxM;
    
    // dp for each
    while (cin >> N >> M){
        if (N == 0 && M == 0) break;

        // compute all valid ks
        memset(val, 1, sizeof(val));
        for (int i=0;i<1<<N;i++){
            // count the number of consective 0s
            int cnt = 0;
            for (int j=0;j<N;j++){
                if ((i >> j) & 1){
                    if (cnt & 1){
                        val[i] = 0;
                        break;
                    }
                    cnt = 0;
                }
                else cnt += 1;
            }
            // check the last group of 0s as well
            if (cnt & 1) val[i] = 0;
        }

        // for (int i=0;i<1<<N;i++) cout << val[i] << '\n';


        // for each valid k, compute all possible ls that can combine with k
        for (int i=0;i<1<<N;i++){
            vl[i].clear();
            for (int j=0;j<1<<N;j++){
                // no overlap and resulting arrangement is valid
                if ((i & j) == 0 && val[i | j]) vl[i].push_back(j);
            }
        }


        memset(dp, 0, sizeof(dp));
        // col -1 doesn't exists, so there cannot be any horizontal blocks extending into col 0
        // any other dp[0][i] = 0
        dp[0][0] = 1;
        // iterate all columns
        for (int i=1;i<M+1;i++){
            // iterate all valid k
            for (int k=0;k<1<<N;k++){
                for (auto l : vl[k]) dp[i][k] += dp[i - 1][l];
            }
        }

        // the final answer is dp[M][0], where all col 0 ~ M - 1 have been filled, and 0 of them extend to col M
        cout << dp[M][0] << '\n';
    }

    return 0;
}