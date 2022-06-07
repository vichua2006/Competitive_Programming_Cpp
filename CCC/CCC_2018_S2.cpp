#include <bits/stdc++.h>
using namespace std;

#define ll long long

int arr[100][100],n;

void rotate(){
    // "rotates a 2D array 90 degrees counter-clockwise"
    int narr[n][n];
    for (int i=0;i<n;i++){
        for (int j=n-1;j>-1;j--){
            narr[n-j-1][i] = arr[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            arr[i][j] = narr[i][j];
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int _min = 1e9; cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> arr[i][j];
            _min = min(_min,arr[i][j]);
        }
    }
    while(arr[0][0] != _min){
        rotate();
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}