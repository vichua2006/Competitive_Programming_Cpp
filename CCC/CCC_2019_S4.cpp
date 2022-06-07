/*

three optimizations so far:
space: explained below
mx: compute once per day, then maintain it through out calculations (avoids recomputation)
total computation: notice that on the jth day, only sites (j-1)*K+r to j*K will be visited

suppose on the jth day and you are at site i
then the minimum amount of steps you took to get to i on the jth day is 
the difference between i and (j-1)*K+1, because that is the furthest you could have went on the previous day
start there, increment backwards and update dp[i][j] until you are K steps away from i
(not r steps, then r+1...K)

but still TLE

I should implement a segmented tree to find the max value within a range
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,K,dp[maxN],s[maxN];
// dp[i][j] denotes last visited site being i on jth day, stored value is max score possible
// since rwo [j] only uses values from row [j-1], we can compress it into 1d
// which solves the MLE issue

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll arrmax(ll a,ll b){
    ll mx = 0;
    for (int i=a;i<=b;i++){
        mx = max(mx,s[i]);
    }
    return mx;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> K;
    for (int i=1;i<N+1;i++) cin >> s[i];
    ll r = N%K;
    // j is the day
    for (int j=1;j<=(N/K)+(r>0);j++){
        // on the jth day, we must visited at least site (j-1)*k+r but at most site j*k
        // (however, on the case where r==0, both bounds will be j*k)
        if (r!=0){
            ll ogmx = arrmax((j-1)*K+1,(j-1)*K+r);
            for (int i=(j-1)*K+r;i<=j*K;i++){
                // find the max of sites within r steps
                ogmx = max(ogmx,s[i]);
                ll mx = ogmx;
                // for all sites p that is between site (j-1)*K+1 to sites K steps away
                for (int p=(j-1)*K+1;p>=1 && i+1-p<=K;p--){
                    // maintain mx
                    mx = max(mx,s[p]);
                    // calculate value when we travel through sites p~i on day j
                    dp[i] = max(dp[i],mx+dp[p-1]);
                }
            }
        }
        else{
            // if there is no remainder, then every step will be K
            ll mx = arrmax(j*K-K+1,j*K);
            dp[j*K] = mx + dp[(j-1)*K];
        }
    }
    cout << dp[N] << '\n';
    return 0;
}