// we first sort the elements
// suppose we can use the first i elements to form every integer in the range [1,si]
// formally, every integer x in the range [1,si] can be deonted as the sum of a subset
// of the set [w1,w2,w3...wi] (1)
// since s1 is now the largest, we now consider si + 1 with w(i+1)
// si + 1 ca be achieved if we can achieve si+1 - w(i+1); because (1),
// si+1 is possible if 1<=si+1 - w(i+1) -> w(i+1) <= si+1
// (we can just find the subset that summed to si+1 - w(i+1) and add w(i+1) to it)
// if the condition if false, we have our answer
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i];
    sort(arr,arr+N);
    ll si = 0;
    for (int i=0;i<N;i++){
        if (si+1<arr[i]){
            break;
        }
        // since we can achieve all value between 1 and si,
        // we can also achieve all of 1+w(i+1),2+w(i+1),...,si+w(i+1)
        // so we can directly set si to si + w(i+1)
        si += arr[i];
    }
    cout << si+1 << '\n';
    return 0;
}