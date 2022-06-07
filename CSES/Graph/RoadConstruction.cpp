//classic DSU 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,m,l[100001],s[100001];

int find(int x){
    while(x != l[x]) x = l[x];
    return x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0;i<n+1;i++){
        l[i] = i;
        s[i] = 1;
    }

    int q1 = n,q2 = 1;
    for (int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        a = find(a); b = find(b);
        if (a != b){
            if (a < b) swap(a,b);
            l[b] = a;
            s[a] += s[b];
            q1 -= 1;
            q2 = max(q2,s[a]);
        }
        cout << q1 << ' ' << q2 << '\n';
    }
    return 0;
}