#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;
bool arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        arr[a] = true;
    }
    for (int i=1;i<N+1;i++){
        if (!arr[i]){
            cout << i << '\n';
            return 0;
        }
    }
}