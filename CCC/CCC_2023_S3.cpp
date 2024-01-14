/*




*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M, R, C;
char g[maxN][maxN];
char filler[] = {'w', 'x', 'y', 'z'};

void IMPOSSIBLE(){
    cout << "IMPOSSIBLE\n";
    exit(0);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> R >> C;

    // entire grid filled with 'a'; default state
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            g[i][j] = 'a';
        }
    }

    if (R == N && C == M){
        ; // can be directly outputed

    } else if (R == N){
        // if odd number of col but total col number is not odd
        if ((C & 1) && !(M & 1)) IMPOSSIBLE();

        // fill last row with b
        for (int i=0;i<M;i++) g[N - 1][i] = 'b';
        
        // fill in center if C is odd; then fill in rest of first row
        if (C & 1) g[0][M / 2] = 'b';
        for (int i=0;i<C/2;i++) g[0][i] = 'b', g[0][M - i - 1] = 'b';

    } else if (C == M){
        // similar logic
        if ((R & 1) && !(N & 1)) IMPOSSIBLE();

        for (int i=0;i<N;i++) g[i][M - 1] = 'b';
        if (R & 1) g[N / 2][0] = 'b';
        for (int i=0;i<R/2;i++) g[i][0] = 'b', g[N - i - 1][0] = 'b';

    } else {
        // fill the first (N - R) by (M - C) grid with filler characters
        // the rest of R rows and C cols will be all 'a' and thus palindromes
        for (int i=0;i<N-R;i++){
            for (int j=0;j<M-C;j++){
                g[i][j] = filler[(i + j) % 4];
            }
        }
    }


    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cout << g[i][j];
        }
        cout << '\n';
    }

    return 0;
}