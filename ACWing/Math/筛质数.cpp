/*

1. for every number (regardless), delete its multiple
time complexity: when i = 2, it loops n/2 times, i = 3 it loops n/3 times
therefore, n/2 + n/3 + n/4 +...+ n/n = n (1/2 + 1/3 +...+ 1/n) ~ n(lnn + C) < nlog2(n)

2. delete only multiple of prime numbers
n (1/2 + 1/3 + 1/5 +...+ 1/p +...) ~ O(n), but it is O(nloglogn) in reality

3. delete composite numbers by their smallest prime factor
this is the most important one for all future number theory algorithms

(refer to code)
first, primes[j] will always be the smallest prime factor (abrev. SPF) in primes[j] * i
1. if i % primes[j] == 0
    since primes[] is in increasing order, pj must be the SPF of i, and is also the SPF of i * pj
2. if i % primes[j] != 0
    this means that pj must be smaller than the SPF of i, and thus is still the SPF of i * pj

next, all composite numbers will be deleted

every composite number n has a SPF, say pj, and there will always exist a number x = n / pj such that pj * x = n

in this sense, every pair of (pj, x) is unique to number n
since pj is n's SPF and x = n / pj  < n, i is guaranteed to iterate to x and filter out n

and notices that each pair of (pj, x) will only be used once, because x is only increasing,
which means that each composite number will only be deleted once, and thus result in a O(n) complexity

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int primes[maxN], cnt = 0;
bool val[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void get_p(int n){
    for (int i=2;i<N+1;i++){
        if (!val[i]){
            val[i] = 1;
            primes[cnt ++ ] = i;
        }
        for (int j=0;primes[j]<=n/i;j++){
            val[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    get_p(N);
    cout << cnt << '\n';
    return 0;
}