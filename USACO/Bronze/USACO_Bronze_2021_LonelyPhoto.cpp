//brute force solution, use prefix sum arrays to have O(1) access to how many
// G/H are in interval [a,b]; go over all [a,b] where b-a >= 3

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 5e5 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,G[maxN],H[maxN],s = 0;
string cows;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> cows;
    for (int i=0;i<N;i++){
        G[i+1] = G[i] + (cows[i] == 'G');
        H[i+1] = H[i] + (cows[i] == 'H'); 
    }
    for (int i=2;i<N;i++){
        for (int j=1;j<N+1-i;j++){
            if (G[j+i]-G[j-1] == 1||H[j+i]-H[j-1] == 1){
                s += 1;
            }
        }
    }
    cout << s << '\n';
    return 0;
}