/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;


void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    string s;
    while (cin >> s){
        if (s == ".") break;
        int N = s.size();
        string a = "";
        for (int i=0;i<N;i++){
            a.push_back(s[i]);
            bool flag = 1;
            for (int j=0;j<N;j++){
                if (s[j] != a[j % a.size()]){
                    flag = 0;
                    break;
                }
            }
            if (flag){
                cout << N / (i + 1) << '\n';
                break;
            }
        }
    }

    return 0;
}