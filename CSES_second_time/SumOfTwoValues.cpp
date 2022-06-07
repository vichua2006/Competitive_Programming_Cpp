#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,X,arr[maxN],sd[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> X;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        arr[i] = a,sd[i] = a;
    }
    sort(sd,sd+N);
    int a = 0,b = N-1,a1 = -1,a2 = -1,idx1,idx2;
    while (a<b){
        if (sd[a]+sd[b]==X){
            a1 = sd[a],a2 = sd[b];
            break;
        }
        if (sd[a]+sd[b]>X) b -= 1;
        else a += 1;
    }
    if (a1 == -1&&a2 == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i=0;i<N;i++){
        if (arr[i]==a1){
            idx1 = i;
            break;
        }
    }
    for (int i=0;i<N;i++){
        if (i==idx1) continue;
        if (arr[i]==a2){
            idx2 = i;
            break;
        }
    }
    cout << idx1+1 << ' ' << idx2+1 << '\n';
    return 0;
}