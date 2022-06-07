//iterating all subsets
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9
int p[15];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n,l,r,x,ans = 0; cin >> n >> l >> r >> x;
    vector<int> s;
    for (int i=0;i<n;i++){
        cin >> p[i];
    }

    for (int i=0;i<pow(2,n);i++){
        s.clear();
        for (int j=0;j<n;j++){
            if (i&1<<j){
                s.push_back(p[j]);
            }
        }
        int _min = INF,_max = 0,sum = 0;
        if (!s.size() >= 2) break;
        for (int a:s){
            _min = min(_min,a);
            _max = max(_max,a);
            sum += a;
        }
        if (sum >= l && sum <= r && _max-_min >= x) ans += 1;
    }

    cout << ans << '\n';

    return 0;
}