/*

to update a subarray (a,b), (c,d) by X
(video: https://www.acwing.com/activity/content/problem/content/832/)

dif[a][b] += X, 
dif[a][d+1] -= X,
dif[c+1][b] -= X,
dif[c+1][d+1] += X;

think in the logic of " the prefix sum of this will include this point..."
and to initialize, we can just apply an update to (a,b), (a,b) and set it to that value

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e3, INF = 1e9;
int N, M ,K;
int arr[maxN][maxN], dif[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            int c; cin >> c;
            dif[i][j] += c, dif[i+1][j] -= c, dif[i][j+1] -= c, dif[i+1][j+1] += c;
        }
    }
    for (int i=0;i<K;i++){
        int a,b,c,d,x; cin >> a >> b >> c >> d >> x;
        dif[a][b] += x, dif[a][d+1] -= x, dif[c+1][b] -= x, dif[c+1][d+1] += x;
    }
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            arr[i][j] = dif[i][j];
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            cout << arr[i][j] << (j==M?'\n':' ');
        }
    }    
    return 0;
}