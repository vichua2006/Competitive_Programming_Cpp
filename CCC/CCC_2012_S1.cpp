
#include<bits/stdc++.h>
using namespace std;

int n;

int C(int n, int r){
    int a = 1;
    for (int i=n;i>n-r;i--){
        a*= i;
    }
    for (int i=1;i<r+1;i++){
        a /= i;
    }
    return a;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    cout << C(n-1,3) << '\n';
    return 0;
}
