
#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n){
    int sqrtn = int(sqrt(n));
    for (int i=2;i<sqrtn+1;i++){
        if (n%i == 0) return false;
    }
    return true;
}


int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t,n; cin >> t;
    for (int i=0;i<t;i++){
        cin >> n;
        for (int j=2;j<n+1;j++){
           if (is_prime(j) && is_prime(2*n-j)){
               cout << j << ' ' << 2*n-j << '\n';
               break;
           }
        }
    }
    return 0;
}