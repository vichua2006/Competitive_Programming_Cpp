//first sort the array, then for every value i, use binary search to try and find x-i is the array
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,X,arr1[maxN],arr2[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool bin_find(ll v){
    ll p = 0;
    int a = 0, b = N-1;
    while(a<=b){
        p = (a+b)/2;
        if (arr2[p] == v) return true;
        if (v < arr2[p]){
            b = p-1;
        }
        else{
            a = p+1;
        }
    }
    return arr2[p] == v;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> X;
    for (int i=0;i<N;i++){
        ll a; cin >> a;
        arr1[i] = a,arr2[i] = a;
    }
    sort(arr2,arr2 + N);
    for (int i=0;i<N;i++){
        if (bin_find(X-arr1[i])){
            for (int j=0;j<N;j++){
                if ((j!=i)&&(arr1[j] == X-arr1[i])){
                    cout << i+1 << ' ' << j+1 <<'\n';
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}