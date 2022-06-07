/*
 
Meet in the middle technique
 
split the group of numbers into two. only use when the two groups can later be combined efficiently
 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array
 
const int maxN = 4e1 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
ll arr1[maxN], arr2[maxN];
vector<ll> v1, v2;
 
void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
 
    cin >> N >> M;
    for (int i=0;i<N/2;i++) cin >> arr1[i];
    for (int i=0;i<N/2 + N%2;i++) cin >> arr2[i];
 
    // N/2
    for (int i=0;i<(1<<(N/2));i++){
        ll sum = 0;
        for (int j=0;j<N/2;j++){
            if (i&(1<<j)) sum += arr1[j];
        }
        v1.push_back(sum);
    }
    // N/2 (+1)
    for (int i=0;i<(1<<(N/2 + N%2));i++){
        ll sum = 0;
        for (int j=0;j<N/2+ N%2;j++){
            if (i&(1<<j)) sum += arr2[j];
        }
        v2.push_back(sum);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll cnt =0;
    for (ll a: v1){
        auto b = equal_range(v2.begin(), v2.end(), M-a);
        cnt += b.second - b.first;
    }  
    cout << cnt << '\n';
}