/*

the only time that will be lost when a lifeguard is fired is the time that the lifeguard spent working alone
sort all the starting and ending points of the lifeguards shift, and then iterate through them
for each lifeguard, compute the amount of time it spends working alone, and then take the minimum of that value over all cows

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int time_alone[maxN];
set<int> act;
vector<ar<int, 2>> indices;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("lifeguards");

    cin >> N;
    for (int i=1;i<N+1;i++){
        int a, b; cin >> a >> b;
        indices.push_back({a, i}), indices.push_back({b, i});
    }

    sort(indices.begin(), indices.end());
    // for practice's sake
    indices.erase(unique(indices.begin(), indices.end()), indices.end());

    ll total_time = 0;
    int pre_time;
    for (int i=0;i<indices.size();i++){
        int curr_time = indices[i][0], cow = indices[i][1];
        // keep tract of the total time;
        // if there was at least one cow between the previous event and the current event, 
        // then the time period is covered
        if (act.size()) total_time += (ll) curr_time - pre_time;
        // check if cow is working alone
        if (act.size() == 1) time_alone[*act.begin()] += curr_time - pre_time;
        // process event
        if (act.count(cow)) act.erase(cow);
        else act.insert(cow);

        pre_time = curr_time;
    }

    ll res = INF;
    for (int i=1;i<N+1;i++) res = min(res, (ll) time_alone[i]);
    cout << total_time - res << '\n';

    return 0;
}