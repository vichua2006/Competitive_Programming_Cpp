// another bellman-ford, but we actually have to find the negative cycle this time


// 22-8-2022 update: so this version actually passes. It has RTE because the maximum N is actually 2500, while it's only set to 2000 here
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e3 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,M,dis[maxN],p[maxN];
vector<ar<ll,3>> e;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    // freopen((name+".out").c_str(),"w",stdout);
}

void BMF(){
    for (int i=0;i<N;i++){
        for (ar<ll,3> v: e){
            ll a = v[0], b = v[1], c = v[2];
            if (dis[b] > dis[a] + c){
                // record parent to find cycle later
                p[b] = a, dis[b] = dis[a] + c;
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("test");

    cin >> N >> M;
    for (int i=0;i<M;i++){
        ll a,b,c; cin >> a >> b >> c;
        e.push_back({a,b,c});
    }
    memset(dis,0x3f,sizeof(dis));
    BMF();
    // the nth round of bellman ford, if there are updates, there is cycle
    for (ar<ll,3> v:e){
        ll a = v[0], b = v[1], c = v[2];
        // b is in a negative loop
        if (dis[b] > dis[a] + c){
            // back track N steps to ensure that we get a node in
            vector<int> ans;
            for (int i=0;i<N;i++) b = p[b];
            int n = b;
            ans.push_back(b);
            b = p[b];
            // then, trace back once more until it reaches that node again
            while (n != b){
                ans.push_back(b);
                b = p[b];
            }
            // the first of the loops needs to be on the back as well
            ans.push_back(n);
            cout << "YES\n";
            for (auto i=ans.end()-1;i >= ans.begin();i--) cout << *i << ' ';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}