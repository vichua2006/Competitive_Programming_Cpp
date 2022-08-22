/*

suppose the rocks are a1, a2,..., an, then the inital position is losing position if and only if a1 ^ a2 ^...^ an = 0

proof

first, the position 0 ^ 0 ^...^ 0 = 0 is a losing position

if a1 ^ a2 ^...^ an = x != 0, then there is always a way to take from a pile so that it becomes 0

suppose the first 1 in x's binary form is at position k. Then there must exist an ai with 1 in position k. This can be proven by contradiction
next, ai > ai ^ x, because XOR will turn the 1 at pos k into 0 whilst the digits to the left (greater) of k remains the same (doesn't matter how the rest changes)

therefore, ai - ai ^ x > 0 and is a valid amount to take from a pile
thus, we can take that amount from ai, and the expression becomes a1 ^ a2 ^...^ ai - (ai - ai ^ x) ^...^ an = a1 ^ a2 ^...^ ai ^ x ^...^ an

since a1 ^ a2 ^...^ an = x, then a1 ^ a2 ^...^ ai ^ x ^...^ an = x ^ x = 0
thus, if we start with an non 0 position, we can always make sure that the opponent receives an 0 position

and if a1 ^ a2 ^...^ an = 0 (1), there is no way to take so that it becomes another 0 position

suppose there does exists ai' < ai such that a1 ^ a2 ^...^ ai' ^...^ an = 0 (2);
then, if we combine both equations: => a1 ^ a1 ^ a2 ^ a2 ^...^ ai ^ ai' ^...^ an = 0
                                    => ai ^ ai' = 0
                                    => ai = ai'
which is a contradicion. ai' does not exists

hence, the opponent could never give us an 0 position, and will always be the one to receive it.

since the rocks are constantly being taken away, the game will evetually end with the opponent having 0, 0, 0...

thus, we will only lose if we start with a1 ^ a2 .. an = 0. Otherwise, we win.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    int res = 0;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        res ^= a;
    }
    if (res) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}