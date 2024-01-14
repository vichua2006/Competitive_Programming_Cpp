/*

the N cows can be sorted by their ability to produce milk, from least to greatest. 
we can claim that the optimal solution must consist of the first X cows from that ordering
being rented, while the remaining N - X is kept for milk.

the renting prices can be orded greedily; if someone is willing to pay more for the same cow, it is 
always optimal to pick then first.

similarly, the stores should also be ordered by their price per gallon; it is most optimal to sell
to the store that is willing to pay more

thus, we can iterate all possible X from 0 to N - 1 and keep the one that produces the most money

for each position i, the sum of renting and amount of milk produced
can be computed in O(1) via prefix/suffix sum, and the sum of milk money can be computed via
binary searching a prefix sum array

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, M, R;
// rent[i] denotes the amount made by renting the first i cows
// milk[i] denotes the amount of milk produced from cow i + 1 to N
ll rent[maxN], milk[maxN];
// price[i] will denote the amount of money made
// if all gallons of the first i stores were sold to
// amoutn[i] denotes the gallons of milk needed to do so
vector<ll> profit, amount;
vector<ar<ll, 2>> stores;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int getIndex(ll x){
    return upper_bound(amount.begin(), amount.end(), x) - amount.begin();
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("rental");

    cin >> N >> M >> R;

    // process milk prices
    for (int i=0;i<N;i++) cin >> milk[i];
    sort(milk, milk + N);
    for (int i=N-1;i>=0;i--) milk[i] += milk[i + 1];
    

    // process store prices
    stores.resize(M + 1);
    // b per gallon for a gallons
    for (int i=0;i<M;i++) cin >> stores[i][1] >> stores[i][0];
    sort(stores.begin(), stores.end());
    reverse(stores.begin(), stores.end());

    profit.resize(M + 1);
    amount.resize(M + 1);
    // profit[0] = 0;
    for (int i=0;i<M;i++){
        ll b = stores[i][0], a = stores[i][1];
        // note the switch to 1-index
        profit[i + 1] = a * b + profit[i];
        amount[i + 1] = amount[i] + a;
    }


    // process the renting prices
    for (int i=1;i<R+1;i++) cin >> rent[i];
    sort(rent + 1, rent + R + 1);
    reverse(rent + 1, rent + R + 1);
    for (int i=1;i<N;i++) rent[i] += rent[i - 1];

    // find the best X
    ll msf = 0;
    for (int i=0;i<=R;i++){
        int pos = getIndex(milk[i]) - 1;
        ll r = rent[i];
        ll p = profit[pos];
        ll extra = (milk[i] - amount[pos]) * stores[pos][0];
        msf = max(msf, r + p + extra);
    }

    cout << msf << '\n';

    return 0;
}