/*

for any lines that rhyme, we must calculate the number of ways it such lines
could be created for each rhyming class,exponentiated them, and add them together
this creates total number of ways a set of rhyming lines can be created

the different sets of lines are independent of each other, so we multiply them together
to calculate the number of ways to form a line of k syllables, we use knapsack dp

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 5e3 + 1,maxM = 1e5+1,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,M,K,dp[maxN],r[26],cls[maxN];
vector<ll> g[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll pM(ll a,ll b,ll m){
    // returns a^b mod m
    ll r = 1;
    while(b>0){
        if (b&1){
            r *= a;
            r %= m;
            b -= 1;
        }
        a = (a*a)%m;
        b /= 2;
    }
    return r;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("poetry");

    cin >> N >> M >> K;
    for (int i=0;i<N;i++){
        ll a,b; cin >> a >> b;
        g[b].push_back(a);
    }
    for (int i=0;i<M;i++){
        char a; cin >> a;
        r[a-'A'] += 1;
    }
    // dp[i] the number of ways to make a line with i syllables
    dp[0] = 1;
    // calulate everything up to the K-1 syllable, the last is save 
    // for calculating specific rhyme classes
    for (int i=1;i<K;i++){
        for (int j=1;j<N+1;j++){
            for (ll a:g[j]){
                dp[i] += (i>=a?dp[i-a]:0),dp[i] %= MOD;
            }
        }
    }
    for (int i=1;i<N+1;i++){
        dp[K] = 0;
        for (ll a:g[i]) dp[K] += (K>=a?dp[K-a]:0),dp[K] %= MOD;
        // for each rhyme class i, cls[i] denotes
        // the number of ways a line ending with a word from class i
        // could be made
        cls[i] = dp[K];
    }
    // then, for each A-Z, we calculate: how many ways are there to create r[A] line that end with class c1,c2,...,cn
    ll ans = 1;
    for (int i=0;i<26;i++){
        ll cnt = 0;
        if (r[i] == 0) continue;
        for (int j=1;j<N+1;j++){
            cnt = (cnt + pM(cls[j],r[i],MOD))%MOD;
        }
        ans *= cnt;
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}