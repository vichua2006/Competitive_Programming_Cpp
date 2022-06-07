// seems like a mix of greedy and number thoery problem
// it appears as if we can work backwards from N
// start from i=2 and go up until i|N, then you can subtract N/i = j from N with cost of i
// repeat process until it reaches 1
// passed, this is a S5?

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n,cost = 0;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    while (n!=1){
        for (int i=2;i<n+1;i++){
            if (n%i == 0){
                // -1 due to fact that cost is calculated from n-n/i and not n
                cost += i-1, n -= n/i;
                break;
            }
        }
    }
    cout << cost << '\n';
    return 0;
}