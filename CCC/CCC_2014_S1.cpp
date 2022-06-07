#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int maxN = 10;

int n,m;
vector<int> v1,v2;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i=1;i<n+1;i++) v1.push_back(i);
    for (int rr=0;rr<m;rr++){
        int r; cin >> r;
        for (int i=0;i<v1.size();i++){
            if ((i+1)%r == 0) continue;
            v2.push_back(v1[i]);
        }
        v1.clear();
        swap(v1,v2);
    }
    for (int a:v1) cout << a << '\n';
    for (int a:v2) cout << a << '\n';
    return 0;
}