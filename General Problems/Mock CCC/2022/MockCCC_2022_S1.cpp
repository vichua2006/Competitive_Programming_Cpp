#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++){
        int a,b,c; cin >> a >> b >> c;
        if (a==0&&b==0&&c==0){
            cout << "NO\n";
            continue;
        }
        if(b==0&&c==0){
            if (a>0&&a%2==0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if (a==0&&b==0){
            cout << "NO\n";
            continue;
        }
        if (a==0&&c==0){
            if (b%2==0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if (c==0){
            if (a>0&&a%2==0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if (a==0){
            cout << "NO\n";
            continue;
        }
        if (b==0){
            if (a>=c&&(a-c)%2==0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        else{
            if (a>=c&&(a-c)%2==0) cout << "YES\n";
            else cout << "NO\n";
            continue;        
        }
    }
    return 0;
}