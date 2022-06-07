//the famous escape room problem,using an array of vectors instead of map
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> r[1000001],s;
bitset<1000001> visited;
int n,m,c;

bool dfs(){
    s.push_back(1);
    visited[1] = 1;
    while(!s.empty()){
        int node = s.back();
        s.pop_back();
        for (int a:r[node]){
            if (!visited[a]){
                if (a == m*n) return true;
                visited[a] = 1;
                s.push_back(a);
            }
        }
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i=1;i<m+1;i++){
        for (int j=1;j<n+1;j++){
            cin >> c;
            r[i*j].push_back(c);
        }
    }
    cout << (dfs()?"yes\n":"no\n");
    return 0;
}