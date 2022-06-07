#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN], dif[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool check(int idx){
    // check if first idx elements form a cycle
    for (int i=idx;i<=idx*((N-1)/idx);i+=idx){
        for (int j=1;j<=idx;j++){
            if (dif[i-idx+j] != dif[j]) return 0;
        }
    }
    // check the ending parts for truncted
    if ((N-1)%idx){
        for (int i=idx*((N-1)/idx)+1;i<N;i++){
            if (dif[i%idx]!=dif[i]) return 0;
        }
    }
    return 1;
}

int solve(){
    // only dif[1~N-1] is used
    for (int i=0;i<N;i++) cin >> arr[i], dif[i] = arr[i]-arr[i-1];
    for (int i=1;i<N;i++){
        if (check(i)) return i;
    }
    return N-1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO("snakes");

    while (1){
        cin >> N;
        if (N) cout << solve() << '\n';
        else break;
    }
    return 0;
}