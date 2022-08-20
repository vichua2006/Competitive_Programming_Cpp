/*

start off by realizing the following situation.

suppose only even index stairs had rocks piles on them. Then, whenever the opponent moves k rockes from 
2n to 2n - 1, we can mimick them and move their k rocks from 2n - 1 to 2n - 2 = 2(n - 1) (another even stair)

eventually, the last rocks will be moved from 2 to 1, and we simply move those onto the ground to win.
hence, we can determine that a position where only even-index stairs have rocks - or, when all odd-indexed stairs are empty - 
is a winning position. if we can forced the opponent into such a position, we win. 

In that sense, we are playing a classical version of nim's game with the rocks in odd positions.
rocks can be "taken away" by moving them to an even position, and if the opponent moves rocks from a even position, 
we simply take the moved rocks and move them to the next even position, which would not change the number of rocks on odd positions.

if we win with nim's game on the odd positions, we win the entire thing. 

and by the proof on the classic nim's game, we only lose if a1 ^ a3 ^ a5 ^...^ a2n+1 = 0. Otherwise, we win.
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
        if ((i + 1) & 1) res ^= a; 
    }
    if (res) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}