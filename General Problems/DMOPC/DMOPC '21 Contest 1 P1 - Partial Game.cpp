/*

notice how each player has "control" over their corresponding piles
thus, it is never optimal to take an odd number of rocks, as it would give the control of the pile to the other player

in addition, both players also want to maximize their steps (under the assumption that their rocks don't increase),
as running out of turns to take means defeat (the other person will just keep taking until no rock remains)
this means that they minimize the number of rocks they take in each step

thus, it is optimal for both players to take 2 rocks at a time.

thus, we just have to count the number of steps each player has

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    ll a = 0, b = 0;
    for (int i=0;i<N;i++){
        ll x; cin >> x;
        if (x & 1) a += x / 2 + 1;
        else b += x / 2;
    }
    if (b > a) cout << "Duke\n";
    else cout << "Alice\n";

    return 0;
}