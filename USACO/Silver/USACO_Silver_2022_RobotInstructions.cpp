/*

another meet in the middle problem
40 instructions, splitting them in half, then piecing the results back together

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 40 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N, X, Y;
ll ans[maxN];
vector<ar<ll,2>> in1, in2;
vector<ar<ll,3>> sub1, sub2;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> X >> Y;
    // read in tow vectors
    for (int i=0;i<N;i++){
        ll a,b; cin >> a >> b;
        // in2 may have 1 more element due to parity
        if (i<N/2) in1.push_back({a,b});
        else in2.push_back({a,b});
    }
    // iterate subsets
    // sub1
    for (int i=0;i<(1<<(N/2));i++){
        ll a = 0, b = 0, cnt = 0;
        for (int j=0;j<N/2;j++){
            if (i&(1<<j)) a += in1[j][0], b += in1[j][1], cnt += 1;
        }
        sub1.push_back({a,b,cnt});
    }
    // sub2
    for (int i=0;i<(1<<(N/2 + N%2));i++){
        ll a = 0, b = 0, cnt = 0;
        for (int j=0;j<N/2 + N%2;j++){
            if (i&(1<<j)) a += in2[j][0], b += in2[j][1], cnt += 1;
        }
        sub2.push_back({a,b,cnt});
    }
    sort(sub1.begin(), sub1.end()), sort(sub2.begin(), sub2.end());
    // binary search for each subset
    for (int i=0;i<sub1.size();i++){
        ll a = sub1[i][0], b = sub1[i][1], c = sub1[i][2];
        int p = -1;
        // search for an instruction with x value of X-a
        for (int b=sub2.size();b>=1;b/=2){
            while (p + b < sub2.size() && sub2[p+b][0] < X - a) p += b;
        }
        p += 1;
        // consider all instruction with x value of X-a
        while (p < sub2.size() && sub2[p][0] == X - a){
            ll x = sub2[p][0], y = sub2[p][1], z = sub2[p][2];
            if (b + y == Y && c + z <= N) ans[c + z] += 1;
            p += 1;
        }
    }
    for (int i=1;i<N+1;i++) cout << ans[i] << '\n';
    return 0;
}