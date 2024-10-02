/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const ll maxN = 1e6 + 10, INF = 1e18, MOD = 1e9 + 7;
int N;
ll arr[maxN], pre[maxN];
set<int> s1, s2;

int nearest(ll dif, set<int> &s){
    int val1 = 0, val2 = 0;
    auto it = s.lower_bound(dif);

    if (it != s.end()) val1 = *it;
    if ((-- it) != s.begin()) val2 = *it;

    return dif + min(abs(dif - val1), abs(dif - val2));
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> arr[i], pre[i] = arr[i] + pre[i - 1], s2.insert(arr[i]);

    ll min_dif = INF, idx = 0, moved_num = -1;
    for (int i=1;i<N+1;i++){
        ll ls = pre[i - 1], rs = pre[N] - pre[i];
        ll dif, nmoved = -1;
        if (ls >= rs){
            ll dif = ls - rs;
            ll n1 = nearest(dif / 2, s1), n2 = nearest(dif / 2 + (dif & 1), s1);
            ll ndif1 = abs(dif - 2 * n1), ndif2 = abs(dif - 2 * n2);
            if (ndif1 < dif || ndif2 < dif){
                if (ndif1 < ndif2) nmoved = n2, dif = ndif1;
                else nmoved = n1, dif = ndif2;
            }
        } else {
            ll dif = rs - ls;
            ll n1 = nearest(dif / 2, s2), n2 = nearest(dif / 2 + (dif & 1), s2);
            ll ndif1 = abs(dif - 2 * n1), ndif2 = abs(dif - 2 * n2);
            if (ndif1 < dif || ndif2 < dif){
                if (ndif1 < ndif2) nmoved = n2, dif = ndif1;
                else nmoved = n1, dif = ndif2;
            }
        }

        if (dif < min_dif){
            min_dif = dif;
            idx = i;
            moved_num = nmoved;
        }

        s2.erase(arr[i]), s1.insert(arr[i]);
    }

    cout << idx << ' ';
    int moved_idx = -1;
    if (moved_num == -1) cout << -1 << '\n';
    else {
        if (pre[idx - 1] >= pre[N] - pre[idx]){
            for (int i=1;i<idx+1;i++){
                if (arr[i] == moved_num){
                    moved_idx = i;
                    break;
                }
            }
        } else {
            for (int i=idx;i<N+1;i++){
                if (arr[i] == moved_num){
                    moved_idx = i;
                    break;
                }
            }
        }
        cout << moved_idx << '\n';
    } 

    return 0;
}