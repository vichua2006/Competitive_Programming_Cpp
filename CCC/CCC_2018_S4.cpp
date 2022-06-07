/*
wow I think this was the hardest dp for me yet
let us model this with a function f(n), denoting the number of PB tree with weight n

therefore, f(n) = f(n/n) + f(n/(n-1))+ .... + f(n/2) (here, / is floor division)

without optinmizations, this is no way in hell going to work since n <= 1e9

first, notice that there will be cases such as f(10/5) and f(10/4), which both results in f(2).
in other words, we don't actually need to compute f N times, but only for the amount of distinct numbers i
of the form n/k for all k in [2,N].

    precisely, there should be 2*sqrt(n) i's, since there are:
    sqrt(n) i's for n/k with k < sqrt(n) (each would be greater than sqrt(n),
    and
    sqrt(n) i's for n/k with k > sqrt(n) (since n/k <= sqrt(n) in this case).

second, we notice that there can be many n/k that result in the same number
for example, f(10/10) = f(10/9) =...= f(10/6) = f(1)
so, f(10) can actually be computed as = 5*f(1) + 2*f(2) + f(3) + f(5)
we don't need to iterate through N, but just those 2*sqrt(n) distinct values
...althought, I really can't figure out how to analyze the time complexity of such a thing

to calculate how many values there are for j = n/k. let us go through k from N to 2
we find the first kx S.T. that j = n/kx. since floor operation follows normal arithmetic to a degree, k1 = n/j
we then find the first ky S.T. j+1 = n/ky. here, ky = n/j+1
therefore, all the k in the range (ky,kx] will result in j = n/k. hence, there are y-x j's
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N;
unordered_map<ll,ll> d;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void solve(ll n){
    // base case
    if (n == 1) return;
    ll cnt = 0,k = n;
    // we start with j = 1 (k = n), and go up to n/2 (k = 2)
    while(k>=2){
        // we obtain j
        ll j = n/k;
        // see if we have already calculated f(j) previously
        if (d[j] == 0) solve(j);
        // then, using the method mentioned above, we obtain the largest kx S.T. n/kx = j, 
        // and the largest ky S.T. n/ky = j+1. now we know that all k in [kx,ky) will result in j, which there are x-y of them
        // and we add (x-y)*f(j) to the total and set k to ky, obtaining the next j. This way, k still iterates through 2-N, but 
        // in O(sqrt(N)) time
        ll kx = n/j, ky = n/(j+1);
        cnt += (kx-ky)*d[j];
        k = ky;
    }
    d[n] = cnt;
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    d[1] = 1;
    solve(N);
    cout << d[N] << '\n';
    return 0;
}