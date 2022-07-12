/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
int arr[30];
bool visited[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=0;i<N;i++){
        string s = "";
        for (int j=0;j<M;j++){
            char a; cin >> a;
            s.push_back(a);
        }
        arr[i] = stoi(s, nullptr, 2);
    }
    int res = 0;
    for (int i=0;i<N;i++){
        int num = 0;
        for (int j=i;j<N;j++){
            num ^= arr[j];
        }
        if (!visited[num]) visited[num] = 1, res += 1;
    }
    cout << res << '\n';
    return 0; 
}