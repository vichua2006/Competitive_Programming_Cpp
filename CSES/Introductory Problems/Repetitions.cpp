#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int L = 1,LL = 1;
string str;
char pre;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> str;
    pre = str[0];
    for (int i=1;i<str.size();i++){
        char a = str[i];
        if (pre == a) L += 1;
        else LL = max(LL,L), L = 1, pre = a;
    }
    LL = max(LL,L);
    cout << LL << '\n';
    return 0;
}