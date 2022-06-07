//for now, I am going to try to run a dfs to search for y
// since the limit of y is 1e18 ~ 1/9 of long long, which is 64 bits, it's probably considered safe 
// to prun numbers with binary representation length exceeding 100
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
ll X,Y,K=1;
unordered_set<string> d;
string str_x = "",str_y = "",ans = "NO\n";

void dfs(string str){
    // get rid of leading zeros
    while(str.back() == '0') str.pop_back();
    if (str == str_y){
        ans = "YES\n";
        return;
    }
    if (d.find(str)!=d.end()) return;
    if (str.size()>100) return;
    d.insert(str);
    reverse(str.begin(),str.end());
    dfs(str);
    str.push_back('1');
    dfs(str);
    return;
}

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> X >> Y;
    while (K<=max(X,Y)){
        str_x.push_back((K&X?'1':'0'));
        str_y.push_back((K&Y?'1':'0'));
        K <<= 1;
    }
    //get rid of leading zeros
    while(str_x.back()=='0') str_x.pop_back();
    while(str_y.back()=='0') str_y.pop_back();
    dfs(str_x);
    cout << ans;
    return 0;
}