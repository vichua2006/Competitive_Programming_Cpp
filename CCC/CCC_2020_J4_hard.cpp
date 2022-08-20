/*

so, it still needed double hashing, and apparently avoiding negative mod is actually an important thing

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e7 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
string S, T;
ull P1 = 13331, P2 = 131;
ull hs1[maxN], hs2[maxN], p1[maxN], p2[maxN];
unordered_set<ull> d1, d2;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
    
    cin >> T >> S;

    int N = T.size(), M = S.size();
    if (M > N){
        cout << "no\n";
        return 0;
    }

    // all the repeating moding probably wasn't necessary, but the "+ MOD"s were, to avoid negative modulus

    // compute rolling hash for T first
    p1[0] = 1, p2[0] = 1;
    for (int i=0;i<N;i++){
        hs1[i + 1] = T[i] + hs1[i] * P1;
        hs2[i + 1] = (T[i] + (hs2[i] * P2) % MOD) % MOD;

        p1[i + 1] = p1[i] * P1, p2[i + 1] = p2[i] * P2 % MOD;
    }
    // compute the hash of S0
    ull shs1 = 0, shs2 = 0;
    for (int i=0;i<M;i++) shs1 = S[i] + shs1 * P1, shs2 = (S[i] + (shs2 * P2) % MOD) % MOD;

    d1.insert(shs1), d2.insert(shs2);
    for (int i=1;i<M;i++){
        shs1 = (shs1 - S[i - 1] * p1[M - 1]) * P1 + S[i - 1];
        shs2 = (((shs2 - (S[i - 1] * p2[M - 1]) % MOD + MOD) % MOD) * P2 + S[i - 1]) % MOD;
        d1.insert(shs1), d2.insert(shs2);
    }

    for (int i=M;i<N+1;i++){
        ull hv1 = hs1[i] - hs1[i - M] * p1[M];
        ull hv2 = (hs2[i] - (hs2[i - M] * p2[M]) % MOD + MOD) % MOD;
        if (d1.count(hv1) && d2.count(hv2)){
            cout << "yes\n";
            return 0;
        }
    }

    cout << "no\n";
    return 0;
}