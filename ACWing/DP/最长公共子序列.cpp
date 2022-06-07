/*
英文是 longest common subsequence (LCS)

side note: appearently, dp state representation is something that is gained through experience
unlike greedy or graph, it requires you to have an archive of problems that you've already done

dp[i][j] = all common subsequences that uses (some of, may not include)
the first i letters of a and first j letters of b. value is max length

the set dp[i][j] can be divided into 4 subsets:

1. we use neither the ith nor the jth letter
2. we use the ith letter only
3. we use the jth letter only
4. we use both ith and jth letter

we discuss the two easy sets first: 1,4

4 only exists if a[i] == b[j], and give a value of dp[i-1][j-1] + 1
1 is just 4 without the +1

now for 2,3
we might instinctively think it's dp[i][j-1] and dp[i-1][j]
but it is not completely equivalent
take 2, for example.
using the ith letter of a != all SS that uses the first i letters
a part of the latter uses i, but another part of it does not.

so there isn't actually a concise formula form for dp[i][j]
but since we are finding the maximum, not completely equivalent is ok

using the ith letter of a != dp[i][j-1], but dp[i][j-1] definitely includes
all common SS that uses the ith letter, so the maximum of that
subset of common SS that uses the ith letter will still be taken into account of
and computed along the rest of dp[i][j-1], but the stored value might be that of a greater
solution. In that case, the smaller solution isn't needed anyway.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN][maxN];
char a[maxN],b[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> a+1 >> b+1;
    //init: dp[0][i] and dp[i][0] is 0 for all i
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            // dp[i-1][j-1] is included in the two sets below
            if (a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
            dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    cout << dp[N][M] << '\n';
    return 0;    
}