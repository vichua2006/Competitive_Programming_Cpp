/*

something new: the states of dp are usually (80% of the problems) computed with the last step before the current state

for example in grid paths (whether its number of paths or min/max weight, whatever), its based on the possible positions we 
could have been at before arrving at the current state, which is either from top or right.

put generally, dp[i][j] is often computed with the states just before they became dp[i][j] by some kind of "last step"
so its often helpful to think about what that last step is (?)


keep this in mind for future problems

*/
#include <iostream>
using namespace std;

const int maxN = 110;

int T, N, M;
int arr[maxN][maxN], dp[maxN][maxN];

int main(){
    cin >> T;
    while (T -- ){  
        cin >> N >> M;
        for (int i=1;i<N+1;i++) for (int j=1;j<M+1;j++) cin >> arr[i][j];
        
        for (int i=1;i<N+1;i++){
            for (int j=1;j<M+1;j++) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
        }
        
        cout << dp[N][M] << '\n';
    }
    
    return 0;
}