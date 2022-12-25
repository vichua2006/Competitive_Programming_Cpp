/*

basically just brute forcing, but I don't understand how it doesn't TLE?

20 strings is 20! worst case, however most of those may not be valid so they will be truncated, but doesn't that still leave room for a lot of 
combinations?

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 20 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, res = 0;
int vis[maxN];
int g[maxN][maxN];
string arr[maxN];

int getOverLap(const string &a, const string &b){
    int A = a.size(), B = b.size();
    for (int i=1;i<min(A, B);i++){
        if (a.substr(A - i, i) == b.substr(0, i)) return i;
    }
    // it is not possible concatinate the two strings together
    return -1;
}

void dfs(int a, int len){
    vis[a] += 1;
    res = max(res, len);

    for (int i=0;i<N;i++){
        if (g[a][i] < 0 || vis[i] >= 2) continue;
        dfs(i, len + arr[i].size() - g[a][i]);
    }

    vis[a] -= 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i];
    char s; cin >> s;

    // precompute adj array, g[i][j] denotes the length lost when string j is placed after string i. -1 denotes that it is not possible to do so
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            g[i][j] = getOverLap(arr[i], arr[j]);
        }
    }

    for (int i=0;i<N;i++){
        if (arr[i][0] == s) dfs(i, arr[i].size());
    }

    cout << res << '\n';

    return 0;
}