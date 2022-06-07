// use map and have type for each time, then go through time in sorted order
// since all arrival and departure times are distinct, it's fine
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;
vector<int> ti;
unordered_map<int,bool> ty;

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
        int a,b; cin >> a >> b;
        ti.push_back(a),ti.push_back(b);
        // arrive is 1, leave is 0
        ty[a] = 1,ty[b] = 0;
    }
    sort(ti.begin(),ti.end());
    int ans = 0,curr = 0;
    for (int a:ti){
        if (ty[a]) curr += 1;
        else ans = max(ans,curr), curr -= 1;
    }
    cout << ans << '\n';
    return 0;
}