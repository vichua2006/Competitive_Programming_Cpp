/*

iterate through the potions and for each potion i, if i does not kill you, drink it.
if not, check if arr[i] is larger than the smallest potion you have taken. If it is, then "undrink" the 
smallest potion and replace it with current i. This will always result in more "room" for future potions and thus is always 
optimal (or that is will only increase the amount of potions drunk)

the smallest potion can be maintained via priority queue, which results in O(nlogn) complexity

this is a reference-worthy greedy solution
https://codeforces.com/problemset/problem/1526/C2

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
priority_queue<int, vector<int>, greater<int>> pq;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    ll hth = 0;
    for (int i=0;i<N;i++){
        ll a; cin >> a;
        if (hth + a < 0){
            if (pq.empty()) continue;
            ll _min = pq.top();
            if (a <= _min) continue;
            pq.pop(); 
            hth -= _min;
        }
        hth += a;
        pq.push(a);
    }
    cout << pq.size() << '\n';
    return 0;
}