//seems doable for my current skills
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1e6+1;
// dp[i] denotes the minimum steps needed for the integer i to reach 0
int N,dp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    memset(dp,0x3f,sizeof dp);
    for (int i=1;i<10;i++) dp[i] = 1;
    for (int i=10;i<N+1;i++){
        int k=10;
        while (k <= i*10){
            // accessing each digit, recomputing dp value
            int d = ((i%k)-(i%(k/10)))/(k/10);
            dp[i] = min(dp[i-d]+1,dp[i]);
            k *= 10;
        }
    }
    cout << dp[N] << '\n';
    return 0;
}