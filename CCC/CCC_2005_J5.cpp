/*

an annoying recursive string problem
the solution is pretty obivous, but implementation and writing the condition take some time and care.

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

bool solve(string &a, int s, int e){
    if (a[s] == 'A'){
        if (s == e) return 1;
        if (a[s + 1] == 'N') return solve(a, s + 2, e);
    }
    if (a[s] == 'B'){
        // first find the position of the matching S
        int ne = -1, cnt = 0;
        for (int i=s+1;i<=e;i++){
            if (a[i] == 'S' && cnt == 0){
                ne = i;
                break;
            }
            if (a[i] == 'B') cnt += 1;
            if (a[i] == 'S') cnt -= 1;
        }
        // B.... (no S), BS, BXXXXS (XXXX not an A word)
        if (ne == -1 || ne == s + 1 || !(solve(a, s + 1, ne - 1))) return 0;

        if (ne == e) return 1;
        if (a[ne + 1] == 'N') return solve(a, ne + 2, e);
    }
    return 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    string a;
    while (1){
        cin >> a;
        if (a == "X"){
            break;
        }
        if (solve(a, 0, a.size()-1)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}