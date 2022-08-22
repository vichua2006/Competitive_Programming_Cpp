/*

euler's totient function: phi(n) counts the number of positive integers less than n that is co-prime to n

e.g. phi(6) = 2 (1 and 5)

suppose n = p1^a1 * p2^a2 * ... * pk^ak

therefore, we need to remove the multiples of p1, p2,..., pk that are less than n

phi(n) = n - n/p1 - n/p2 - ... - n/pk ...

however, consider the multiples of p1 * p2. they were over-counted, deleted once by p1, and then again with p2
so, they needed to be added back once

+ n/(p1 * p2) + n/(p1 * p3) + ... + n/(pk-1 * pk) ...

now consider multiples of p1 * p2 * p3. they were deleted thrice and added back thrice, but actually need to be deleted

- n/(p1 * p2 * p3) ... and on, following the priciple of Inclusion-Exculsion of sets

notice that we can factor out a n:

n(1 - 1/p1 - 1/p2 - ... - 1/pk + 1/(p1 * p2) + 1/(p1 * p3) + ... + 1/(pk-1 * pk) - 1/(p1 * p2 * p3)...) (1)

= n(1 - 1/p1)(1 - 1/p2)(...)(1 - 1/pk) (2)
the expansion of (2) equals (1)

= phi(n)

hence, we only need to compute the prime factors of n to compute phi(n), which can be done in O(sqrt(n)) time 

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
    while (N -- ){
        int a; cin >> a;
        int res = a;
        for (int i=2;i<=a/i;i++){
            if (a % i == 0){
                // res = res * (1 - 1/i), rearranged so that it can be computed without floats
                // 1 - 1/i = (i - 1)/i
                // divid first to prevent overflow
                res = res / i * (i - 1);
                while (a % i == 0) a /= i;
            }
        }
        if (a > 1) res = res / a * (a - 1);
        cout << res << '\n';
    }

    return 0;
}