// nope still doesn't pass after implementing SGT

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N,K,dp[maxN],s[maxN],tsize = 1;
vector<ll> tree;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void compute(ll r){
    if (r>=tsize) return;
    compute(2*r),compute(2*r+1);
    tree[r] = max(tree[2*r],tree[2*r+1]);
    return;
}

ll qry(ll a,ll b){
    a += (tsize-1),b += (tsize-1);
    ll res = 0;
    while (a<=b){
        if (a%2==1) res = max(res,tree[a]),a += 1;
        if (b%2==0) res = max(res,tree[b]),b -= 1;
        a /= 2,b /= 2;
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> K;
    while(tsize<N) tsize *= 2;
    tree.resize(2*tsize,0);
    for (int i=1;i<N+1;i++){
        ll a; cin >> a;
        s[i] = a;
        tree[i+tsize-1] = a;
    }
    compute(1);
    ll r = N%K;
    for (int j=1;j<=(N/K)+(r!=0);j++){
        if (r!=0){
            ll ogmx = qry((j-1)*K+1,(j-1)*K+r);
            for (int i=(j-1)*K+r;i<=j*K;i++){
                ogmx = max(ogmx,s[i]);
                ll mx = ogmx;
                for (int p=(j-1)*K+1;p>=1 && i-p+1<=K;p--){
                    mx = max(mx,s[p]);
                    dp[i] = max(dp[i],mx + dp[p-1]);
                }
            }
        }
        else{
            ll mx = qry((j-1)*K+1,j*K);
            dp[j*K] = mx + dp[(j-1)*K];
        }
    }
    cout << dp[N] << '\n';
    return 0;
}