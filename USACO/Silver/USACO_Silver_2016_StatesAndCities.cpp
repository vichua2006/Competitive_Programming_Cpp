//usual mapping problem
//don't over complicate with data structures - the simpler the better
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,ans = 0;
string a,b;
unordered_map<string,int> S;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    freopen("citystate.in","r",stdin);
    freopen("citystate.out","w",stdout);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        S[a.substr(0,2)+b] += 1;
    }
    for (auto p:S){
        string s1 = p.first.substr(0,2),s2 = p.first.substr(2,2);
        if ((S.find(s2+s1) != S.end()) && (s1 != s2)){
            ans += p.second*S[s2+s1];
        }
    }
    cout << ans/2 << '\n';
    return 0;
}