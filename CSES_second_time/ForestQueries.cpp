#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,Q,pre[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<N+1;j++){
            char a; cin >> a;
            pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(a=='*');
        }
    }
    for (int i=0;i<Q;i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        cout << pre[c][d]-pre[a-1][d]-pre[c][b-1]+pre[a-1][b-1] << '\n';
    }
    return 0;
}