//brute force
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,arr1[7],arr2[7];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool check(ll A[7], ll B[7]){
    for (int i=0;i<7;i++){
        if (A[i]!=B[i]) return false;
    }
    return true;
}

void solve(){
    for (int i=0;i<7;i++){
        for (int j=i+1;j<7;j++){
            for (int k=j+1;k<7;k++){
                arr2[0] = arr1[i];
                arr2[1] = arr1[j];
                arr2[2] = arr1[k];
                arr2[3] = arr1[i]+arr1[j];
                arr2[4] = arr1[i]+arr1[k];
                arr2[5] = arr1[j]+arr1[k];
                arr2[6] = arr1[i]+arr1[j]+arr1[k];
                sort(arr2,arr2+7);
                if (check(arr1,arr2)){
                    cout << arr1[i] << ' ' << arr1[j] << ' ' << arr1[k] << '\n';
                    return;
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int t=0;t<N;t++){
        for (int i=0;i<7;i++) cin >> arr1[i];
        solve();
    }
    return 0;
}