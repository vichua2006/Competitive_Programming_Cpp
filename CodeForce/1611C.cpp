// if n is not one of the two outer most numbers, it is impossible
// since the original method was to pick the smallest of the two
// to reconstruct, we pick the largest of the two each time, and push it into whatever side they were on
// this needs to be done with a deque, or else .pop_front() would most definitely cause TLE

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;
deque<int> A,P;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int t=0;t<N;t++){
        int n;cin >> n;
        P.clear(),A.clear();
        for (int i=0;i<n;i++){
            int a; cin >> a;
            A.push_back(a);
        }
        if (A.front() != n&&A.back() != n){
            cout << -1 << '\n';
            continue;
        }
        for (int i=0;i<n;i++){
            if (A.back()>A.front()){
                P.push_back(A.back());
                A.pop_back();
            }
            else{
                P.push_front(A.front());
                A.pop_front();
            }
        }
        for (int i=0;i<n;i++) cout << P[i] << (i == n-1?'\n':' ');
    }
    return 0;
}