#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 100000;
int s1[maxN],s2[maxN],n,k = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s1[i];
    }
    for (int i=0;i<n;i++){
        cin >> s2[i];
    }
    int ss1 = 0,ss2 = 0;
    for (int i=0;i<n;i++){
        ss1 += s1[i];
        ss2 += s2[i];
        if (ss1 == ss2) k = i+1;
    }
    cout << k << '\n';
    return 0;
}