/*

thought I knew this well enough, nope.

i * i < n is wrong, because i * i has the risk of overflow (actually, this can be also avoided with ll)
i < n / i is the recommended syntax

*/

#include <iostream> 
using namespace std;

int N;

int main(){
    cin >> N;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        bool flag = 1;
        if (a == 1) flag = 0;
        // *** this line here ***
        for (int j=2;j<=a/j;j++){
            if (a % j == 0){
                flag = 0;
                break;
            }
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}