//sort and simulate the process

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,g;
pair<int,pair<int,int>> l[1000000];
unordered_map<int,int> m;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> g;
    int high = g,a,b,c;
    for (int i=0;i<n;i++){
        cin >> a >> b >> c;
        l[i] = {a,{b,c}};
    }
    sort(l,l+n);

    for (int i=0;i<n;i++){
        a = l[i].first,b = l[i].second.first,c = l[i].second.second;
        if (m.find(a) == m.end()){
            m[a] = g;
        }
        for ()
    }   
}