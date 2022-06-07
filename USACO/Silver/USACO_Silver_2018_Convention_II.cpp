//just simulation? for skipping from one event to another, use priority queue from now on
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
// use priority queue to store time of 'events', arrival and departure of cows
// main algorithm: --> process all current events and add to waiting --> check if cow is done --> assign new cow to eat if done
priority_queue<pair<ll,pll>> event;
priority_queue<pair<ll,ll>> waiting;
unordered_map<ll,ll> arrive;

ll n,s,a,t,wait_time = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);

    cin >> n;
    for (int i=0;i<n;i++){
        //                - i will be the seniority of the cow
        cin >> a >> t;
        event.push({-a,{-i,t}});
    }

    bool grazing = false;
    //                   - while they are not both empty
    while(! (event.empty() && waiting.empty())){
        //               -process next event (whatever it might be)
        ll curr_time = event.top().first;
        while((event.top().first == curr_time) && !event.empty()){
            s = event.top().second.first,t = event.top().second.second;
            event.pop();
            if (t == -1){
                grazing = false;
            }
            else{
                arrive[s] = -curr_time;
                waiting.push({s,t});
            }
        }

        if ((!grazing) && (!waiting.empty())){
            //                   - the time this cow finish eating grass, { this cow's seniority, -1 (time)}
            event.push({curr_time-waiting.top().second,{waiting.top().first,-1}});
            wait_time = max(-curr_time-arrive[waiting.top().first],wait_time);
            grazing = true;
            waiting.pop();
        }
    }
    cout << wait_time << '\n';

    return 0;
}
