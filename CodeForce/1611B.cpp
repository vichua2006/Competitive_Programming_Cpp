// another binary search problem
// we know the theoretical limit of the number of teams (say, x): min(a,b)
// and want to find a x such that check(x) is true and x is as large as possible
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool check(int teams,int m,int cs){
    if (teams > min(m,cs)) return false;
    // each teams needs at least one of each;
    m -= teams, cs -= teams;
    // then each team needs two more people, doesn't matter who
    return (cs + m >= 2* teams);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int t=0;t<N;t++){
        int a,b,ans = 0; cin >> a >> b;
        for (int bin = min(a,b);bin>=1;bin/=2){
            while(check(ans + bin,a,b)) ans += bin;
        }
        cout << ans << '\n';
    }
    return 0;
}