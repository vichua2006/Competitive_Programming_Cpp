// logic is that you should always pick the movie that ends first
// because it allows you to have more events to pick from
// supposed you pick some other event. At best, it would allow you
// to have same number of options if you were to pick the one that ended soonest
// since picking others does not increase the number of events picked, picking
// the one that ends first is optimal
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;
//ending time mapped to starting times
set<int> endtime;
unordered_map<int,vector<int>> events;

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
        events[b].push_back(a);
        endtime.insert(b);
    }
    sort(endtime.begin(),endtime.end());
    int cnt = 0,currtime = 0;
    for (auto et:endtime){
        // check if we can attend this event
        for (int start:events[et]){
            if (start>=currtime){
                currtime = et;
                cnt += 1;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}