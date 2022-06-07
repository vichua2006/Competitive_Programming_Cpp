#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int maxR = 1e3 + 1;

int n,reading[maxR],m1,m2;
unordered_map<int,vector<int>> m;

ar<int,2> minmax(vector<int> v){
    // returns the minimum and maximum value in v
    int mi = 1e9, mx = 0;
    for (int a: v) mx = max(mx,a), mi = min(mi,a);
    return {mi,mx};
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i=0;i<n;i++){
        int a; cin >> a;
        reading[a] += 1;
    }
    for (int i=1;i<maxR;i++){
        m[reading[i]].push_back(i);
        if (reading[i] > m1){
            m2 = m1;
            m1 = reading[i];
        }
        else if (reading[i] > m2) m2 = reading[i];
    }
    ar<int,2> p;
    if (m[m1].size() > 1){
        p = minmax(m[m1]);
        cout << abs(p[0]-p[1]) << '\n';
        return 0;
    }
    if (m[m2].size() > 1){
        p = minmax(m[m2]);
        cout << max(abs(m[m1].front()-p[0]),abs(m[m1].front()-p[1])) << '\n';
        return 0;
    }
    cout << abs(m[m1].front()-m[m2].front()) << '\n';
    return 0;
}
