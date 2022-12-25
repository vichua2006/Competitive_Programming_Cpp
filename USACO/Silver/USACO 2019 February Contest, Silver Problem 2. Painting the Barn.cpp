/*

revisiting the problem probably a year later, I realize that is in fact a difference array
we range update all the paint, and then compute the original array and count the number of tiles with value k

also, it seems like that the input is give as the coordinates  of the intersections of the grids,
so there are some slight offset

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, K;
int arr[maxN][maxN], dif[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("paintbarn");

    cin >> N >> K;
    int x = 0, y = 0;
    for (int i=0;i<N;i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        // 1-indexed is more convenient for prefix sum
        a ++ , b ++ , c ++ , d ++ ;
        x = max(x, d), y = max(y, d);
        dif[a][b] += 1, dif[a][d] -= 1, dif[c][b] -= 1, dif[c][d] += 1;
    }

    int cnt = 0;
    for (int i=1;i<x+1;i++){
        for (int j=1;j<y+1;j++){
            arr[i][j] = dif[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            if (arr[i][j] == K) cnt += 1;

            // cout << arr[i][j] << ' ';
        }
        // cout << '\n';
    }

    cout << cnt << '\n';

    return 0;
}