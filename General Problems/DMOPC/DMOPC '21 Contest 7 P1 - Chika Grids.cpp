/*

almost like dp, fill the grid top down, and for each cell check the one before and above it to see if it satisfies the conditions

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 15e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M;
ll arr[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            cin >> arr[i][j];
            if (!arr[i][j]) arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) + 1;
            if (arr[i][j] <= arr[i][j - 1] || arr[i][j] <= arr[i - 1][j]){
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++) cout << arr[i][j] << (j == M ? '\n' : ' ');
    }

    return 0;
}