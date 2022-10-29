/*

dp[i][j][k] will denote the maximum number of soldiers placed considering the first i columns, with the 
ith col being placed like j and the i - 1 col being placed like k. we need to consider two columns back because their attack range can indeed extend that far.

to compute dp[i][j][k], we need to check for two things:
1. a soldier is not placed on a hill
2. whether the configuration is valid (no friendly fire)

for 1, new trick in code

for 2
let a, b, c denote the configuration of the i, i - 1, and i - 2 col respectively
if (a & b & c), it means that they overlap eachother

and since i <= 100, j <= 1024, k <= 1024, memory might not hold, so we need to use two arrays instead, one storing the i - 1 and the other one used for 
computing the ith col

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 100 + 10, maxM = 1 << 11, INF = 1e9, MOD = 1e9 + 7;
int N, M;
int hill[maxN], cnt[maxM];
int dp[2][maxM][maxM];
vector<int> st;

bool check(int x){      // checks if the arrangment is valid
    int zz = INF;       // counts the distance from the last 1
    for (int i=0;i<N;i++){
        if ((x >> i) & 1){
            if (zz < 2) return false;
            zz = 0;
        } else {
            zz += 1;
        }
    }

    return true;
}

int count(int x){
    int cnt = 0;
    while (x){
        if (x & 1) cnt += 1;
        x >>= 1;
    }

    return cnt;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> M >> N;
    // store the arrangement of hills as a binary number, makes conditions really easy 
    for (int i=1;i<M+1;i++){
        for (int j=0;j<N;j++){
            char a; cin >> a;
            if (a == 'H') hill[i] += 1 << j;
        }
    }

    // compute all valid states
    for (int i=0;i<(1<<N);i++){
        if (check(i)){
            st.push_back(i);
            cnt[i] = count(i);
        }
    }

    // init: all of dp[0] is set to 0
    // answer is dp[M + 2][0][0], placing no soldiers on the N + 2 nor the N + 1 col
    for (int i=1;i<M+3;i++){
        for (int j=0;j<st.size();j++){
            for (int k=0;k<st.size();k++){
                for (int l=0;l<st.size();l++){
                    int a = st[j], b = st[k], c = st[l];
                    // if their attack range overlaps
                    if ((a & b) || (b & c) || (a & c)) continue;
                    // if there's a soldier placed on a hill
                    if (hill[i] & a) continue;

                    // instead of memcpy, we can simply switch between two arrays 
                    // by their parity like so
                    dp[i & 1][a][b] = max(dp[i & 1][a][b], dp[(i - 1) & 1][b][c] + cnt[a]);
                }
            }
        }
    }

    cout << dp[(M + 2) & 1][0][0] << '\n';

    return 0;
}