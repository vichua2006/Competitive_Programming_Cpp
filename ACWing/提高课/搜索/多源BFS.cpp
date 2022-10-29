/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 20 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
set<string> arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("evolution");

    cin >> N;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        for (int j=0;j<a;j++){
            string str; cin >> str;
            arr[i].insert(str);
        }
    }

    vector<string> v1, v2;
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            v1.clear(), v2.clear();
            for (auto a: arr[i]){
                if (!arr[j].count(a)) v1.push_back(a);
            }
            for (auto a: arr[j]){
                if (!arr[i].count(a)) v2.push_back(a);
            }

            for (int k=0;k<v1.size();k++){
                for (int l=0;l<v2.size();l++){
                    for (int u=0;u<N;u++){
                        if (arr[u].count(v1[k]) && arr[u].count(v2[l])){
                            cout << "no\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "yes\n";

    return 0;
}