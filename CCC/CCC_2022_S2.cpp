#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1, INF = 1e9, MOD = 1e9 + 7;
int N, M, K;
vector<ar<string,2>> same, dif;
unordered_map<string, int> d;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++){
        string a,b; cin >> a >> b;
        same.push_back({a,b});
    }
    cin >> M;
    for (int i=0;i<M;i++){
        string a,b; cin >> a >> b;
        dif.push_back({a,b});
    }
    cin >> K;
    for (int i=0;i<K;i++){
        string a,b,c; cin >> a >> b >> c;
        d[a] = i, d[b] = i, d[c] = i;
    }
    int cnt = 0;
    for (auto a:same) if (d[a[0]] != d[a[1]]) cnt += 1;
    for (auto a:dif) if (d[a[0]] == d[a[1]]) cnt += 1;
    cout << cnt << '\n';
    return 0;
}