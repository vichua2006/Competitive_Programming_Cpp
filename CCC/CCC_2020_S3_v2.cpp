/*

learned acwing's ull moding method, with a double hash.
made the fatal mistake of not counting the actual number of answers but instead outputting
the size of one of the two sets, which would not have equaled the answer due to collisons

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, H, P1 = 131, P2 = 13331;
int cnt[26], tar[26];
ull hs1[maxN], p1[maxN], hs2[maxN], p2[maxN];
char ndl[maxN], hsk[maxN];
string n, h;
unordered_set<ull> s1, s2;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool check(){
    for (int i=0;i<26;i++){
        if (tar[i] != cnt[i]) return 0;
    }
    return 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> n >> h;
    N = n.size(), H = h.size();
    for (int i=0;i<N;i++) ndl[i + 1] = n[i];
    for (int i=0;i<H;i++) hsk[i + 1] = h[i];

    for (int i=1;i<N+1;i++) tar[ndl[i] - 'a'] ++ ;
    // compute rolling hash
    p1[0] = 1, p2[0] = 1;
    for (int i=1;i<H+1;i++){
        hs1[i] = hs1[i - 1] * P1 + hsk[i], hs2[i] = ((hs2[i - 1] * P2) % MOD + hsk[i]) % MOD;
        p1[i] = p1[i - 1] * P1, p2[i] = (p2[i - 1] * P2) % MOD;
    }
    // partially fill up cnt for convenience's sake
    for (int i=1;i<N;i++) cnt[hsk[i] - 'a'] ++ ;

    int res = 0;
    for (int i=N;i<H+1;i++){
        cnt[hsk[i] - 'a'] ++ ;
        if (check()){
            ull hv1 = hs1[i] - hs1[i - N] * p1[N];
            ull hv2 = (hs2[i] - (hs2[i - N] * p2[N]) % MOD + MOD) % MOD;
            if ((!s1.count(hv1)) || (!s2.count(hv2))){
                s1.insert(hv1);
                s2.insert(hv2);
                res ++ ;
            }
        }
        cnt[hsk[i - N + 1] - 'a'] -- ;
    }
    cout << res << '\n';
    return 0;
}
