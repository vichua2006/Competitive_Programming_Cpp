// DSU, then just use node 1 as dummy and test connectivity
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,l[maxN],s[maxN];
vector<ar<int,2>> r;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int find(int x){
    if (x!=l[x]) l[x] = find(l[x]);
    return l[x];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++) l[i] = i,s[i] = 1;
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        a = find(a),b = find(b);
        if (a!=b){
            if (s[a] < s[b]) swap(a,b);
            l[b] = a;
            s[a] += s[b];
        }
    }
    for (int i=1;i<N+1;i++){
        int a = find(i),b = find(1);
        if (a!=b){
            if (s[a] < s[b]) swap(a,b);
            l[b] = a;
            s[a] += s[b];
            r.push_back({a,b});     
        }
    }
    cout << r.size() << '\n';
    for (ar<int,2> a:r){
        cout << a[0] << ' ' << a[1] << '\n';
    }
    return 0;
}