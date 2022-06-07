/*
previous version not working, rewrite. comments later

okay so this is currently 11:20, so it's brief
dp[l][r] = whether or not the range [l,r] can be combined into one riceball
and for each range, we literally just:
1. go over every [l,a) and [a,r] and see if they can combine (two riceballs)
2. go over every [l,a),[a,b-1) and [b,r] and see if they can combine (three riceballs)

1. can only work if sum[l,a)==sum[a,r] AND dp[l][a-1]&&dp[a][l]
2. is same but instead rice1 == rice3 AND all three smaller riceballs must combine

this is O(N^4), with N <= 400, TLE for sure (256e8)

two optimizations.
obvious one: stop when you find a way to combine an interval instead of continuing on to find more ways
the total sum will be pre[r]-pre[l-1] regardless of what way you combine it with
this reduces complexity, but I don't think is enough

not so obvious one:
for three riceballs, the two on each side must have equal sum
since all riceballs are positive, their size will only increase
Hence, two pointers can eb applied: 
if [l,a) > [b,r], then shift a right, vice versa shift b left
in the case where [l,a) == [b,r] but the middle can't be combined, just increment one of the pointers (think through what happens next)

this reduces complexity to O(N^3) which is enough to pass
(wow that's not brief at all)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 4e2 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,pre[maxN];
bool dp[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    int ans = 0;
    //in,compute prefix,init
    for (int i=1;i<N+1;i++) cin >> pre[i],
    pre[i] += pre[i-1],dp[i][i] = 1,ans = max(ans,pre[i]-pre[i-1]);
    // size of interval
    for (int s=1;s<=N-1;s++){
        for (int l=1;l<=N-s;l++){
            int r = l+s;
            bool combined = 0;
            for (int a=l+1;a<=r;a++){
                int rice1 = pre[a-1]-pre[l-1],rice2 = pre[r]-pre[a-1];
                if (rice1 == rice2&&(dp[l][a-1]&&dp[a][r])){
                    dp[l][r] = 1,ans = max(ans,pre[r]-pre[l-1]);
                    combined = 1;
                    break;
                }
            }
            if (combined||s==1) continue;
            int a = l+1,b = r;
            while(a<b){
                // since [l,a) = [b,r], we can use two pointer to further optinmize:
                // if [l,a) > [b,r], then shift a right, vice versa shift b left
                int rice1 = pre[a-1]-pre[l-1],rice2 = pre[b-1]-pre[a-1],rice3 = pre[r]-pre[b-1];
                if (rice1==rice3&&(dp[l][a-1]&&dp[a][b-1]&&dp[b][r])){
                    dp[l][r] = 1,ans = max(ans,pre[r]-pre[l-1]);
                    break;
                }
                // NOTE: when WA, do usual list, but then check THOROUGHLY with conditions.
                // debugged this for 0.5h because I wrote "rice1>rice2" instead of the following:
                if (rice1<rice3) a += 1;
                else b -= 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}