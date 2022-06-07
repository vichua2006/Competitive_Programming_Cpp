// implementation
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int Q;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> Q;
    for (int i=0;i<Q;i++){
        ll a; cin >> a;
        // find out what the length of the final number is though finding the positions of each of the powers of 10
        ll length = 1, m = 1, b = 0;
        while (b + 9*m*length < a){
            // find the closest power of 10 to a, b is right before the 1
            b += 9*m*length, m *= 10, length += 1;
        }
        // if mod == 0, it means that the position is on the last digit of an number, else, it goes into the next number
        string fn = to_string(m + (a-b)/length - ((a-b)%length == 0));
        if ((a-b)%length == 0) cout << fn.back() << '\n';
        else cout << fn[(a-b)%length - 1] << '\n';
    }
    return 0;
}