// basic DP/recursion, but this one requires the moves, so recursion is better
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

void solve(int a,int b, int c,int n){
    // moving a stack of n disks from a to c
    if (n == 0) return;
    // first we move all but the last disk from a to b
    solve(a,c,b,n-1);
    // move last disk to c
    cout << a << ' ' << c << '\n';
    // move the rest onto c
    solve(b,a,c,n-1);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    // can mathematically prove that it takes 2^k - 1 steps
    cout << (1<<N)-1 << '\n';
    solve(1,2,3,N);
    return 0;
}