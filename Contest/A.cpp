/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
char all[maxN][11], a[11], b[11];
int len[maxN], dp[11][11];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int minED(int n, int m){
    bool f1 = 1, f2 = 1;
    for (int i=1;i<n+1;i++){
        dp[i][1] = dp[i - 1][1] + 1;
        if (a[i] == b[1] && f1) dp[i][1] -= 1, f1 = 0;
    }
    for (int i=1;i<m+1;i++){
        dp[1][i] = dp[1][i - 1] + 1;
        if (a[1] == b[i] && f2) dp[1][i] -= 1, f2 = 0;
    }

    for (int i=2;i<n+1;i++){
        for (int j=2;j<m+1;j++){
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + int(a[i] != b[j]));
        }
    }

    return dp[n][m];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<N;i++){
        string str; cin >> str;
        len[i] = str.size();
        for (int j=1;j<=len[i];j++) all[i][j] = str[j - 1];
    }

    for (int i=0;i<M;i++){
        string str; cin >> str;
        int lim; cin >> lim;
        int l = str.size();
        for (int j=1;j<=l;j++) b[j] = str[j - 1];

        int cnt = 0;
        for (int j=0;j<N;j++){
            for (int k=1;k<=len[j];k++) a[k] = all[j][k];

            if (minED(len[j], l) <= lim) cnt += 1;
        }
        cout << cnt << '\n';
    }

    return 0;
}