//sort and then two pointers: a at min p, b max p
// if a + b > x, then b must ride it by himself, so b--
// worth noting is that recursive logic is oddly reassuring
// once b is gone, b-1 becomes max p, and process continues
// bit of a special case when a=b, but eh.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,X,arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> X;
    for (int i=0;i<N;i++) cin >> arr[i];
    int a = 0, b = N-1,cnt = 0;
    sort(arr,arr+N);
    while(a<=b){
        if (a==b){
            cnt += 1,a += 1, b-=1;
            continue;
        }
        if (arr[a]+arr[b]>X) b -= 1,cnt += 1;
        else a += 1, b -= 1,cnt += 1;
    }
    cout << cnt << '\n';
    return 0;
}