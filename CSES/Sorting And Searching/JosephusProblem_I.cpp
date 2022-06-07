// simulate the process with two vectors 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,K=2;
bool act[maxN];
vector<int> v1,v2;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) v1.push_back(i+1);
    int p = K-1;
    while (v1.size()){
        v2.clear();
        for (;p<v1.size();p+=K){
            act[v1[p]] = 1;
            cout << v1[p] << ' ';
        }
        for (int a:v1){
            if (!act[a]) v2.push_back(a);
        }
        p = p%(int)v1.size();
        v1 = v2;
    }
    return 0;
}