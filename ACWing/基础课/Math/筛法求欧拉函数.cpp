/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int primes[maxN], phi[maxN], cnt = 0;
bool val[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;

    // 1 is coprime to any number by definition
    phi[1] = 1;

    for (int i=2;i<N+1;i++){
        if (!val[i]){
            primes[cnt ++ ] = i;
            // for any prime number p, phi[p] = p - 1
            phi[i] = i - 1; 
        }
        for (int j=0;primes[j]<=N/i;j++){
            val[primes[j] * i] = 1;
            if (i % primes[j] == 0){
                // keep in mind that for a number n with prime factor p1, regardless if it has p1^1 or p1^100
                // phi[n] will always have (1 - 1/p1)
                // in this case, pj is already a prime factor of i, so phi[i] would look like:
                // i(1 - 1/p1)(...)(1 - 1/pj)
                // which means that phi[primes[j] * i] = primes[j] * i * (1 - 1/p1)(...)(1 - 1/pj)
                // = pj * phi[i];
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            }
            // in cases where i does not already contain primes[j], primes[j] must be the smallest prime factor
            // of primes[j] * i, which means its totient function expression needs to contain (1 - 1/pj)
            // therefore, phi[primes[j] * i] = primes[j] * i * (1 - 1/p1)(...)(1 - 1/pk)(1 - 1/primes[j])
            // = primes[j] * phi[i] * (1 - 1/primes[j]) = phi[i] * (primes[j] - 1)
            phi[primes[j] * i]  = phi[i] * (primes[j] - 1);
        }
    }
    ll res = 0;
    for (int i=1;i<N+1;i++) res += (ll) phi[i];
    cout << res << '\n';
    return 0;
}