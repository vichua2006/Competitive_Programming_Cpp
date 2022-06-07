/*

every number can be expressed in the form:

a = (p1^k1)(p2^k2)...(pn^kn)

number of factors is equal to (k1+1)(k2+1)...(kn+1)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1,INF = 1e9;
int N;

ll countD(int x){
    ll ans = 1;
    for (int i=2;i*i<=x;i++){
        ll cnt = 1;
        // find k when p = i;
        while (x%i==0){
            cnt += 1;
            x /= i;
        }
        ans *= cnt;
    }
    // check if there is still one extra factor left (if so, then multiple (1+1) to ans)
    if (x!=1) ans *= 2;
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        cout << countD(a) << '\n';
    }
    return 0;
}