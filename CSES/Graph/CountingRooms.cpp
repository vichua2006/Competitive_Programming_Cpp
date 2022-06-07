//basic graph 
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,m,ans = 0;
string arr[1000];

bool e(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m&&arr[i][j]=='.';
}

void solve(int x,int y){
    arr[x][y] = '#';
    if(e(x,y-1)) solve(x,y-1);
    if(e(x,y+1)) solve(x,y+1);
    if(e(x-1,y)) solve(x-1,y);
    if(e(x+1,y)) solve(x+1,y);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (e(i,j)){
                solve(i,j); ans ++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}