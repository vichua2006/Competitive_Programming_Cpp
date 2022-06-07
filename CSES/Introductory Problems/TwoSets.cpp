//another construction problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N;
bool visited[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    ll S = N*(N+1)/2;
    if (S&1) cout << "NO\n";
    else{
        //divide by 2
        S >>= 1;
        int C = 0;
        cout << "YES\n";
        for (ll i=N;i>0;i--){
            if (S > i){
                S -= i;
                visited[i] = true;
                C += 1;
                continue;
            }
            // if S <= i
            visited[S] = true;
            C += 1;
            break;
        }
        cout << C << '\n';
        for (int i=1;i<N+1;i++){
            if (visited[i]) cout << i << ' ';
        }
        cout << '\n';
        cout << N-C << '\n';
        for (int i=1;i<N+1;i++){
            if (!visited[i]) cout << i << ' ';
        }
    }
    return 0;
}