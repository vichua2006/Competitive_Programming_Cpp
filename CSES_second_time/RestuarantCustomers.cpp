/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
vector<ar<int,2>> vec;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++){
        int a,b; cin >> a >> b;
        vec.push_back({a,1}),vec.push_back({b,0});
    }
    sort(vec.begin(),vec.end());
    int cnt = 0,ans = 0;
    for (ar<int,2> a:vec){
        if (a[1]) cnt += 1;
        else cnt -= 1;
        ans = max(ans,cnt);
    }
    cout << ans << '\n';
    return 0;
}