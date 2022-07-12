/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N, C;
ll p[maxN], pre[maxN];


void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> C;
    for (int i=0;i<N;i++){
        ll a; cin >> a;
        p[a] += 1;
    }
    // compute prefix array
    pre[0] = p[0];
    for (int i=1;i<C;i++) pre[i] += p[i] + pre[i-1];
    // two pointer through; a is where point a is, and b denotes the furthest possible second point from a
    // c points can be directed computed using prefix sum 
    ll a = 0, b = 1, curr = 0, sum = 0, hf = C/2;    
    for (; a < hf; a++){
        // only curr = Lb * Lc is maintained, a is not taken into consideration
        for (; b < a + hf + (C&1); b++){
            // for each new b point, p[b]* (possible "c"s)
            curr += p[b] * (pre[min(C-1, b + hf -1 + (C&1))] - pre[a + hf]);
        }
        sum += p[a] * curr;
        // when a increments by 1, we lose 1 b and 1 c
        // the c position (actually includes the b position)
        curr -= (a+1 + hf < a + 2*hf - 1 + (C&1) ? p[a+1 + hf] : 0) * (pre[a + hf - 1 + (C&1)] - pre[a]);
    }
    
    cout << sum << '\n';
    return 0;
}