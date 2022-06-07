/*

classic greedy algorithm, but I still didn't realize
suppose we look at the largest group of 0s, seperated by surrounding 1s

if we want to combine this range with an adjacent one to gain a bigger value
the adjacent range must have an even greater value k1 < k2 for k1 < (k1+k2)/2

but since k1 is the lagest group, k2 doesn't exists, so this is impossible
so k1 must be taken by itself

then, removing k1 from the list, the second-largest kx becomes the new largest
...
by this recursive logic, we just pick the first K batches of 0s and add them together

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,K;
int ent[maxN];
vector<int> score;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> K;
    string str; cin >> str;
    for (int i=0;i<N;i++) ent[i] = (str[i]=='1');
    int cnt = 0;
    for (int i=0;i<N;i++){
        if (ent[i]) score.push_back(cnt),cnt = 0;
        else cnt += 1;
    }
    if (cnt) score.push_back(cnt);
    sort(score.begin(),score.end());
    reverse(score.begin(),score.end());
    int ans = 0;
    for (int i=0;i<min(K,int(score.size()));i++) ans += score[i];
    cout << ans  << '\n';
    return 0;
}