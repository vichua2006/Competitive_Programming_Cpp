#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 100;
int n,arr[maxN];


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int idx = n/2 + (n%2);
    vector<int> m1(arr,arr+idx),m2(arr+idx,arr+n);
    reverse(m1.begin(),m1.end());
    for (int i=0;i<idx-(n%2);i++){
        cout << m1[i] << ' ' << m2[i] << ' ';
    }
    if (n%2 == 1) cout << m1[idx-1] << '\n';
}