/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int T, N;
int arr[maxN];
// dp[i] denotes who wins when considering the last i piles
bool dp[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T -- ){
        cin >> N;
        for (int i=N;i>0;i--) cin >> arr[i];
        // 0 is losing, 1 is winning
        dp[1] = 1;
        for (int i=2;i<N+1;i++){
            // if the current pile only has one, then we must take it
            if (arr[i] == 1) dp[i] = dp[i - 1] ^ 1;
            // else, there's always a way for the first player to be in a winning position
            else dp[i] = 1;
        }

        if (dp[N]) cout << "First\n";
        else cout << "Second\n";
    }

    return 0;
}