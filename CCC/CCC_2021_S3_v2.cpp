//binary search version, checks left and right of mid and search the lesser side
//how does one prove that the graph is convex for all p in [0,10^9] ?
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
    ll upper = 1e9,lower = 0,mid,m,r,l;
    while (lower <= upper){
        mid = lower + (upper-lower)/2;
        m = solve(mid);l = solve(mid-1); r = solve(mid+1);
        if (m > l && m > r){
            break;
        }
        if (m == r || m == l){
            break;
        }
        if (r > m){
            upper = mid-1;
        }
        if (l > m){
            lower = mid+1;
        }
    }
    cout << m << '\n';
    return 0;
}
