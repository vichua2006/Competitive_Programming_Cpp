/*

ax + by + cz = n, and a + b + c needs to be max
we can iterate over, say, x and y, and solve for z

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 4e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();
 
    cin >> N;
    int a, b, c; cin >> a >> b >> c;
    int msf = 0;
    for (int i=0;i<N+1;i++){
        for ( int j=0;j<N+1;j++){
            // z = (n - ax - by) / c
            if (N - a*i - b*j < 0 || (N - a*i - b*j)%c != 0) continue;
            int k = (N - a*i - b*j) / c;
            msf = max(msf, i + j + k);
        }
    }
    cout << msf << '\n';
    return 0;
}