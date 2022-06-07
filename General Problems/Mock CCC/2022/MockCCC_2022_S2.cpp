// all "I" need to be in position 0,2,4...2n-2
// therefore shortest needed is moving each I back into it's respective position
// holy shit always beware of integer over flow
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6, INF = 1e9, MOD = 1e9 + 7;
ll N,C=0;
string str;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    cin >> str;
    int temp = 0;
    for (int i=0;i<2*N;i++){
        if (str[i] == 'I'){
            C += abs(2*temp-i);
            temp += 1;
        }
    }
    cout << C << '\n';
    return 0;
}