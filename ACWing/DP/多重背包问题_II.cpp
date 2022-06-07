/*

now s<=2000, so it needs optinmization
first step is to realize that a bounded knapsack can be transformed into 
01 knapsack by splitting up the s items. However, that would still result in a complexity of 
O(N*V*S), which is the same as regular BKP

Next step is to realize that we do not need to split s items into s items, but
only need to make sure that we can choose any number of items in the range [0,s]

To achieve this in as few "groups" as possible, we split the items into floor(log2(S))+1 groups
    
    say, s = 10:
    then we can split the items into groups of 1,2,4, and 3
    1,2,4 can create numbers up to 7. In order to reach up to 10, we take 10
    and subtract 1+2+4, we get 3. since we can create 0~7, if we add 3 to each combination
    we can get 3~10

since we can still pick everything in [0,s], the answer is correct
this reduces the complexity to O(N*V*log(s))

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e3 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN];
vector<int> v,w;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        int vi,wi,si; cin >> vi >> wi >> si;
        for (int k=1;si-k>=0;k*=2){
            si -= k;
            v.push_back(k*vi),w.push_back(k*wi);
        }
        if (si > 0) v.push_back(si*vi),w.push_back(si*wi);
    }
    //the rest is identical to 01knapsack 1d dp
    for (int i=0;i<v.size();i++){
        for (int j=M-1;j>=v[i];j--){
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout << dp[M] << '\n';
    return 0;
}