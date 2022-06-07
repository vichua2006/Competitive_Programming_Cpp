// 2 dimensional prefix sum, simple enough
// arr[i][j] would be the sum of the subarray starting at the top right
// and ening at (i,j)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e3 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,Q,arr[maxN][maxN];


void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=1;i<N+1;i++){
        string line; cin >> line;
        for (int j=1;j<N+1;j++){
            // compute sum
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            if (line[j-1] == '*') arr[i][j] += 1;
        }
    }
    for (int i=0;i<Q;i++){
        int y1,x1,y2,x2; cin >> y1 >> x1 >> y2 >> x2;
        // some indexing issues; needed to be adjusted by 1 to get the correct cell
        cout << arr[y2][x2] - arr[y1-1][x2] - arr[y2][x1-1] + arr[y1-1][x1-1] << '\n';
    }
    return 0;
}