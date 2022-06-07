/* 

nb comp 2018 q8

01 knapsack with the twist of keeping tract of selected items (done with binary numbers)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
int dp[maxN], item[maxN];
vector<int> v, w;
vector<string> name;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> M >> N;
    for (int i=0;i<N;i++){
        string a; int b,c; cin >> a >> b >> c;
        name.push_back(a), v.push_back(b), w.push_back(c);
    }
    for (int i=0;i<N;i++){
        for (int j=M;j>=v[i];j--){
            if (dp[j] < dp[j-v[i]] + w[i]){
                dp[j] = dp[j-v[i]] + w[i];
                item[j] = item[j-v[i]]^(1<<i);
            }
        }
    }
    for (int i=0;i<N;i++){
        if (item[M]&(1<<i)) cout << name[i] << '\n';
    }
    cout << dp[M] << '\n';
    return 0;
}