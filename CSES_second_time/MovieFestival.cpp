#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
set<int> arr;
unordered_map<int,vector<int>> d;

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
        arr.insert(b),d[b].push_back(a);
    }

    int curr = 0,cnt = 0;
    for (int a:arr){
        for (int b:d[a]){
            if (b>=curr){
                cnt += 1;
                curr = a;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}