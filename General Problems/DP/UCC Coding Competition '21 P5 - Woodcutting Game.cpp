/*

dp, with game theory logic brute and force all possibilities.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2 + 1,maxM = 301,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
// 0 is losing, 1 is winning
// a,b,c,d
bool dp[maxN][maxM][maxN][maxM], act[maxN][maxM][maxN][maxM];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}



void f(int a, int b, int c, int d){
    // written recursively because it is hard to figure out the order of computation for dp > 3 dimensions
    if (act[a][b][c][d]) return;


    // general thinking: if A can force B into losing state, A is winning
    // cut a,b
    // Update : there's a statement:If you choose Option 2, you can cut any integer between  and 1 (inclusive) 10 off the width
    if (a == 2){
        f(1, b, 1, b);
        f(1, b, c, d);
        dp[a][b][c][d] |= (!dp[1][b][1][b]) || (!dp[1][b][c][d]);
    }
    for (int i=1;i<b;i++){
        f(a, i, a, b - i);
        dp[a][b][c][d] |= (!dp[a][i][a][b-i]);
    }
    for (int i=1;i<min(b, 11);i++){
        f(a, b - i, c, d);
        dp[a][b][c][d] |= (!dp[a][b-i][c][d]);
    }

    // cut c,d
    if (c == 2){
        f(1, d, 1, d);
        f(a, b, 1, d);
        dp[a][b][c][d] |= (!dp[1][d][1][d]) || (!dp[a][b][1][d]);
    }
    for (int i=1;i<d;i++){
        f(c, i, c, d - i);
        dp[a][b][c][d] |= (!dp[c][i][c][d-i]);
    }
    for (int i=1;i<min(d, 11);i++){
        f(a, b, c, d - i);
        dp[a][b][c][d] |= (!dp[a][b][c][d-i]);
    }

    // debugging, see if we can construct for loop of that order
    cout << a << ' ' << c << ' ' << b << ' ' << d << '\n';
    
    act[a][b][c][d] = 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    int N, M, K , L;
    cin >> N >> M >> K >> L;
    // defined losing state
    act[1][1][1][1] = 1;
    
    f(N, M, K, L);

    cout << (dp[N][M][K][L] ? 'W' : 'L') << '\n';
    return 0;
}