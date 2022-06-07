#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define maxN 100000

int arr[maxN];

bool non_d(int n){
    for (int i=1;i<n;i++){
        if (arr[i-1] > arr[i]) return false;
    }
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t,n; cin >> t;
    for (int ti=0;ti<t;ti++){
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        int T = 0;
        while(!non_d(n)){
            T += 1;
            for (int i=1;i<n;i++){
                if (arr[i-1] > arr[i]) arr[i] += 1<<(T-1);
            }
        }
        cout << T << '\n';
    }
    return 0;
}