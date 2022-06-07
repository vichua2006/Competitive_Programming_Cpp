// editorial: dp[l][r] = maximum score player 1 can get when it is being played in the interval [l,r]
// ???
// okay, I think I understand a bit of this
// all situations where l == r == i for some i in [0,N] (i.e. interval includes 1 element), dp[l][r] = value[i];
// then, for any l,r, dp[l][r] = max(v[l] + min(dp[l+1][r-1],dp[l+2][r]),v[r] + min(dp[l+1][r-1],dp[l][r-2]))
// P1 can either first take the leftmost element or the rightmost. The two is symmetrical
// suppose P1 takes left. Because P2 will be playing optimally, he would pick the one that leads to the most points
// which is max(dp[l+1][r-1],dp[l+2][r]), forcing P1 to take min(dp[l+1][r-1],dp[l+2][r])
// so P1 would pick the choice that leads to the most points for themself, 
// namely, max(v[l] + min(dp[l+1][r-1],dp[l+2][r]),v[r] + min(dp[l+1][r-1],dp[l][r-2]))
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 5e3 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,v[maxN],dp[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> v[i];
    // dp, but this time the end goal is dp[1][N]?
    for (int r=1;r<N+1;r++){
        for (int l=r;l>0;l--){
            // l is l, i is r
            // dp looks weird right?
            // for each (l,r), it requires: (l+2,r), (l+1,r-1), (l,r-2)
            //  *   @
            //    *
            //      *
            // @:(l,r) (top left 1,1 bottom right N,N)
            // initialization
            if (r == l) dp[r][l] = v[r];
            else{
                // other cells being initialized to zero is fine, i think
                dp[l][r] = max(
                v[l] + min(dp[l+1][r-1],dp[l+2][r]),
                v[r] + min(dp[l+1][r-1],dp[l][r-2])
                );
            }
        }
    }
    cout << dp[1][N] << '\n';
    return 0;
}