//given a N by N square where N <= 1e9 in the form
// 1 2 3 4...N
// N+1 N+2 ...
// ...
// .........N^2
//K rotation operations are applied, each with a,b,c,d
// coordinates of a spuare, and rotate it by 90 cw
// then Q queries, each asking what the number is in cell (x,y)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 5e3 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,K,Q;
ar<ll,4> rot[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> K >> Q;
    for (int i=K-1;i>-1;i--){
        ll a,b,c,d; cin >> a >> b >> c >> d;
        rot[i] = {a,b,c,d};
    }
    for (int i=0;i<Q;i++){
        ll x,y; cin >> x >> y;
        for (int i=0;i<K;i++){
            ar<ll,4> k = rot[i];
            ll a = k[0],b = k[1],c = k[2],d = k[3];
            if (a<=x&&x<=c&&b<=y&&y<=d){
                ll nx,ny;
                // undo the k-ith rotation
                // ith row would become ith col
                ll crow = x-a,ccol = y-b;//0 indexed
                ny = b+crow,nx = c-ccol;
                x = nx, y = ny;
            }
        }
        cout << N*(x-1) + y << '\n';
    }
    return 0;
}