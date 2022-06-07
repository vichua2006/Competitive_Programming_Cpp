#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define d double

int n;
d area = 0,arr1[100001],arr2[100000];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n+1;i++){
        cin >> arr1[i];
    }
    for (int i=0;i<n;i++){
        cin >> arr2[i];
    }
    for (int i=0;i<n;i++){
        area += min(arr1[i],arr1[i+1])*arr2[i] + abs(arr1[i]-arr1[i+1])*arr2[i]/2;
    }
    cout.precision(5);
    cout << fixed << area << '\n';
    return 0;
}