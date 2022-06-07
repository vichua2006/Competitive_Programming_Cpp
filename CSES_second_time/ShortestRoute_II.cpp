#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const ll maxN = 5e2+1,INF = 1e18;

ll N,M,Q,dis[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<i;j++){
            dis[i][j] = INF;
        }
    }
    for (int i=0;i<M;i++){
        ll a,b,c; cin >> a >> b >> c;
        if (a<b) swap(a,b);
        dis[a][b] = min(dis[a][b],c);
    }
    for (int v=1;v<N+1;v++){
        for (int i=1;i<N+1;i++){
            for (int j=1;j<i;j++){
                dis[i][j] = min(dis[i][j],dis[max(i,v)][min(i,v)]+dis[max(j,v)][min(j,v)]);
            }
        }
    }
    for (int i=0;i<Q;i++){
        ll a,b; cin >> a >> b;
        if (a<b) swap(a,b);
        cout << (dis[a][b]==INF?-1:dis[a][b]) << '\n';
    }
    return 0;
}