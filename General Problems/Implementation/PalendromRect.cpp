// given a grid of N by M character, outptu a graid S.T.
// every row and col is a palindrome, otherwise report -1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e3 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M;
char g[maxN][maxN];
unordered_map<int,char> d;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool row(){
    for (int i=1;i<N+1;i++){
        for (int j=1;j<=M/2 + (M&1);j++){
            if (g[i][j] != '.'&&g[i][M+1-j] == '.') g[i][M+1-j] = g[i][j];
            if (g[i][M+1-j] != '.'&&g[i][j] == '.') g[i][j] = g[i][M+1-j];
            if (g[i][j]!=g[i][M+1-j]) return false;
        }
    }
    return true;
}

bool col(){
    for (int i=1;i<M+1;i++){
        for (int j=1;j<=N/2 + (N&1);j++){
            if (g[j][i] != '.'&&g[N+1-j][i] == '.') g[N+1-j][i] = g[j][i];
            if (g[N+1-j][i] != '.'&&g[j][i] == '.') g[j][i] = g[N+1-j][i];
            if (g[j][i]!=g[N+1-j][i]) return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        string line; cin >> line;
        for (int j=1;j<M+1;j++){
            g[i][j] = line[j-1];
        }
    }
    // rows will not interfere with another, either will col
    // but they will affect each other, therefore, do two rounds
    bool a = row(), b = col(), c = row(), d = col();
    if (a&&b&&c&&d){
        for (int i=1;i<N+1;i++){
            for (int j=1;j<M+1;j++){
                if (g[i][j] == '.') cout << 'a';
                else cout << g[i][j];
            }
            cout << '\n';
        }
    }
    else cout << -1 << '\n';
    return 0;
}