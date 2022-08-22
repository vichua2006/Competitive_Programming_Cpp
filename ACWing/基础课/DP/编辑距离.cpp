/*

strings are at most length 10
so for each query, compute the edit distance for every string

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 11,INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxK][maxK];
string arr[maxN],str;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int eddis(string s1,string s2){
    memset(dp,0,sizeof(dp));
    int n = s1.size(),m = s2.size();

    bool v = 1;
    for (int i=1;i<n+1;i++){
        dp[1][i] = dp[1][i-1] + 1;
        if (s2[0] == s1[i-1]&&v) dp[1][i] -= 1,v = 0;
    }
    v = 1;
    for (int i=1;i<m+1;i++){
        dp[i][1] = dp[i-1][1] + 1;
        if (s2[i-1] == s1[0]&&v) dp[i][1] -= 1,v = 0;
    }
    for (int i=2;i<n+1;i++){
        for (int j=2;j<m+1;j++){
            dp[j][i] = min(dp[j-1][i-1]+(s1[i-1]!=s2[j-1]),min(dp[j-1][i]+1,dp[j][i-1]+1));
        }
    }
    for (int i=1;i<n+1;i++){
        for (int j=1;j<m+1;j++){
            cout << dp[j][i] << ' ';
        }
        cout << '\n';
    }
    return dp[m][n];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    int cnt = 0;
    for (int i=1;i<N+1;i++) cin >> arr[i];
    for (int i=0;i<M;i++){
        int k; cin >> str >> k;
        cnt = 0;
        for (int j=1;j<N+1;j++){
            cnt += (eddis(str,arr[j])<=k);
        }
        cout << cnt <<'\n';
    }
    return 0;
}