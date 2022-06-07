/*
CCC prep

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e4+1,INF = 1e9;
int N;
pair<int,string> arr[maxN];

// wants greatest score, but lexicogrphically least, so custom
// compare is used for sake of sanity

bool cmp(pair<int,string> a,pair<int,string> b){
    if (a.first!=b.first) return a.first>b.first;
    else {
        string s1 = a.second,s2 = b.second;
        for (int i=0;i<min(s1.size(),s2.size());i++){
            if (s1[i]!=s2[i]){
                return s1[i] < s2[i];
            }
        }
        return 1;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++){
        string str;
        int a,b,c; cin >> str >> a >> b >> c;
        arr[i] = {2*a+3*b+c,str};
    }
    sort(arr,arr+N,cmp);
    for (int i=0;i<min(N,2);i++) cout << arr[i].second << '\n';
    return 0;
}