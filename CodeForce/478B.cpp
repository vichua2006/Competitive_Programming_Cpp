/*

greedy solution, kinda

first, each team must have at least one member, so in reality, we can only distribute N - M participants

for Kmax, we aim for maximum increase of friends per member added into a team. This would suggest that the opimal solution would be to keep adding members to the same team
(for a team of size k, a new member would provide k new pairs.)
for Kmin, we aim for the minimum increase per member added, which means that the participants should be even distributed
(from each team with a single member, keep adding till all teams have 2, then 3, then 4, and so on. Each step ensure an minimum amount of new pairs made
and thus an overall minimum amount of friends)

these two numbers can be computed in O(1) using basic math 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N, M;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    ll kmax = (N - M) * (N - M + 1) / 2, kmin = (M - N%M) * ((N / M) * (N / M - 1) / 2) + (N%M) * ((N / M) * (N / M + 1) / 2);
    cout << kmin << ' ' << kmax << '\n';
    return 0;
}