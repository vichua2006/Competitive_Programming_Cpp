/*

range dp - i'll write comments later

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 4e2 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,dp[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    memset(dp,0,sizeof(dp));
    int ans = 0;
    //prefix sum for calculating riceball sum in O(1)
    for (int i=1;i<N+1;i++) cin >> dp[i][i],ans = max(ans,dp[i][i]);
    for (int s=1;s<N;s++){
        //size of interval
        bool combined = 0;
        for (int l=1;l<=N-s;l++){
            int r = l+s;
            for (int ptr=l+1;ptr<=r;ptr++){
                // two ricebal type first, see if [l,ptr) can combine [ptr,r]
                if ((dp[l][ptr-1]&&dp[ptr][r])&&(dp[l][ptr-1]==dp[ptr][r])){
                    dp[l][r] = 2*dp[ptr][r];
                    ans = max(ans,dp[l][r]);
                    // if interval is already combined, then there's no need to continue
                    combined = 1;
                    break;
                }
            }
            if (combined) continue;
            
            // now three riceballs: combine [l,a),[a,b),[b,r]
            if (s>=2){
                int a = l+1,b = r;
                // since [l,a) = [b,r], we can use two pointer to further optinmize:
                // if [l,a) > [b,r], then shift a right, vice versa shift b left
                while(a<b){
                    if (dp[l][a-1]&&dp[a][b-1]&&dp[b][r]){
                        if (dp[l][a-1] == dp[b][r]){
                            dp[l][r] = dp[l][a-1] + dp[a][b-1] + dp[b][r];
                            ans = max(ans,dp[l][r]);
                            break;
                        }
                        if (dp[l][a-1]>dp[b][r]) a += 1;
                        else b -= 1;
                    }
                    else{
                        if(!dp[l][a-1]) a += 1;
                        else b -= 1;
                    } 
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}