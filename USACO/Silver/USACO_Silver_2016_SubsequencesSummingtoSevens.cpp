/*

if the sum of a contigeous groups of cows is divisible by seven,
it would mean that pre[i]-pre[j-1] = 0 mod 7 (pre is prefix sum of arr)

or

pre[i] = pre[j-1] mod 7

since we want the longest length possible, we can just record the smallest position i
such that pre[i] = k mod 7, where k = 1,2,...,6

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int pos[7];

void setIO(string name){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO("div7");

    cin >> N;
    memset(pos,0x3f,sizeof(pos));
    pos[0] = 0;
    ll sum = 0,msf = 0;
    for (int i=1;i<N+1;i++){
        ll a; cin >> a;
        sum += a;
        msf = max(msf,(ll) i-pos[sum%7]);
        pos[sum%7] = min(pos[sum%7],i);
    }
    cout << msf << '\n';
    return 0;
}