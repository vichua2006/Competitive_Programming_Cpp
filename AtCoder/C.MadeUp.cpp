//another mapping problem,although this one can be solved without using any mapping
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 1e5;
int A,B,C,n;
ll ans = 0;
unordered_map<int,vector<int>> mA,mB,mC;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> A;
        mA[A-1].push_back(i);
    }
    for (int i=0;i<n;i++){
        cin >> B;
        mB[B-1].push_back(i);
    }
    for (int i=0;i<n;i++){
        cin >> C;
        mC[C-1].push_back(i);
    }

    for (auto a:mA){
        int v = a.first,c = 0;
        if (mB.find(v) != mB.end()){
            for (int i=0;i<mB[v].size();i++){
                c += mC[mB[v][i]].size();
            }
        }
        ans += (ll) a.second.size()*c;
    }
    cout << ans << '\n';
    return 0;
}