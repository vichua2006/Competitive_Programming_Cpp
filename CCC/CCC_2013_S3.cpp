// dfs or recursion
// compute all remaining games, apply dfs search on remaining games
// use 4x4 array to keep track of matches, if not played, play it.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int t,n,points[5], ans =0;
// m[i][j] denotes whether i has played j
bool matches[5][5];
vector<ar<int,2>> p;

void solve(){
    if (p.empty()){
        // all matches are now played, check if there exists a team whose score is >= favorite team
        for (int i=1;i<5;i++){
            if (points[i] >= points[t] && i != t){
                return;
            }
        }
        ans += 1;
        return;
    }
    ar<int,2> m = p.back(); p.pop_back();
    int a = m[0], b = m[1];
    // match was already played
    if (matches[a][b]){
        solve();
        return;
    }
    // go through the three possible outcomes of one match
    points[a] += 3;
    solve();
    points[a] -= 3, points[b] += 3;
    solve();
    points[b] -= 2, points[a] += 1;
    solve();
    points[a] -= 1, points[b] -= 1;

    p.push_back({a,b});
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t >> n;
    for (int i=0;i<n;i++){
        int a,b,sa,sb; cin >> a >> b >> sa >> sb;
        // being lazy here
        points[a] += 3*(sa>sb) + (sa==sb);
        points[b] += 3*(sb>sa) + (sa==sb);
        matches[a][b] = true;
        matches[b][a] = true;
    }
    for (int i=1;i<5;i++){
        for (int j=i+1;j<5;j++){
            p.push_back({i,j});
        }
    }
    solve();
    cout << ans << '\n';
    return 0;
}