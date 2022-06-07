/*

this problem was classifed as ad-hoc, but greedy also works

note that for every sequence 1 2 3 4 5 ... m, there are m*(m+1)/2 good samples
from there, we can precisely control the number of good samples we add

for example, if we add 1 to the end of the previous sequence: 1 2 3 4 5 ... m 1
the new samples would be : {1}, {1, m}, {1, m, m-1} ... {1, m, m-1, ... , 3, 2}. m in total

generally, if an element that was last used at position k was appended again at position l, it would bring l - k nwe good samples

by this mechanism, we can also determine the maximum possible good samples for any given n >= m

    m*(m + 1)/2 + (n - m)*m

and the minimum is n

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
ll N, M, K;
// pos[i] denotes the last position number i appeared in
ll arr[maxN], pos[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> K;
    // 
    if (K > M*(M + 1)/2 + (N - M)*M || K < N){
        cout << -1 << '\n';
        return 0;
    }

    ll sum = 0;
    // pos is entirely initalized to 0
    for (int i=1;i<N+1;i++){
        ll note = (i % M) + 1;
        // new samples + sum + postions that can be filled as 1
        // i - pos[note] + sum + N - i = sum + N - pos[note]
        if (sum + N - pos[note] > K){
            // compute new smaples needed
            ll ns = K - sum - N + (ll)i;
            // then the req. note is arr[i - ns] (assuming that no notes repeated during this interval)
            arr[i] = arr[i - ns];
            // fill the rest with arr[i]
            for (int j=i+1;j<N+1;j++) arr[j] = arr[i];
            break;
        }
        // else just keep filling
        arr[i] = note;
        sum += (ll)i - pos[note];
        pos[note] = i;
    }
    for (int i=1;i<N+1;i++) cout << arr[i] << (i==N ? '\n' : ' ');
    return 0;
}