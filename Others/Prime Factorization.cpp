#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ll long long

const int maxN = 1e3+1;
int n;

void solve(int n){
    vector<int> f;
    while(n % 2 == 0){
        n /= 2;
        f.push_back(2);
    }
    int lim = 0;
    for (int i=3;i<sqrt(n)+1;i+=2){
        while(n % i == 0){
            n /= i;
            f.push_back(i);
        }
    }
    if (n > 2){
        f.push_back(n);
    }
    for (int a:f){
        cout << a << ' ';
    }
    cout << '\n';
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i=0;i<n;i++){
        int b; cin >> b;
        solve(b);
    }
    return 0;
}