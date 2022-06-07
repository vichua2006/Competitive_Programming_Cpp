//uses ternary search, you can guarentee that the graph of F(x) has only one minimum value
//isn't working for whatever reason
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll f[200000][3];

ll solve(ll c){
    ll count = 0,p,w,d;
    for (int i=0;i<n;i++){
        p = f[i][0],w = f[i][1],d = f[i][2];
        if (p-d <= c && c <= p+d){
            //          -within hearing range
            continue;
        }
        if (c > p+d){
            count += (c-p-d)*w;
        }
        if (c < p-d){
            count += (p-d-c)*w;
        }
    }
    return count;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> f[i][0] >> f[i][1] >> f[i][2];
    }
    ll upper = 1e9,lower = 0,p1,p2,t1,t2,res;

    while (lower <= upper){
        p1 = lower + (upper-lower)/3;
        p2 = lower + (upper-lower)*2/3;
        t1 = solve(p1);t2 = solve(p2);
        res = min(t1,t2);

        if (t1 == t2){
            lower = p1+1;upper = p2-1;
        }
        if (t1 < t2){
            upper = p2-1;
        }
        if (t1 > t2){
            lower = p1-1;
        }
    }
    cout << res << '\n';
    return 0;
}