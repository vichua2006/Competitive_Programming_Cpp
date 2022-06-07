#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<N;i++) cin >> arr[i];
    sort(arr,arr+N);
    int cnt = 0,a = 0,b = N-1;
    while (a<=b){
        if (a==b){
            cnt += 1;
            break;
        }
        if (arr[a]+arr[b]<=M) a += 1,b -= 1,cnt += 1;
        else b -= 1,cnt += 1;
    }
    cout << cnt << '\n';
    return 0;
}