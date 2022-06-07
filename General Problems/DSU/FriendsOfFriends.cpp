#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,q,l[100001],s[100001];

int find(int x){
    while(x != l[x]) x = l[x];
    return x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;
    for (int i=0;i<n+1;i++){
        l[i] = i;
        s[i] = 1;
    }
    int a,b,c;
    for (int qq=0;qq<q;qq++){
        cin >> a;
        if (a == 1){
            cin >> b >> c;
            b = find(b);c = find(c);
            //if b and c are are already connected, connecting again would cause chaos
            if (b == c) continue;
            if (b < c) swap(b,c);

            l[c] = b;
            s[b] += s[c];
        }
        if (a == 2){
            cin >> b;
            cout << s[find(b)] << '\n';
        }
    }
    return 0;
}