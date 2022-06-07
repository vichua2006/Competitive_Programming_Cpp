#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9
const int maxN = 1e5+1;

vector<int> b[maxN];
int n,m,p;

void bfs(){
    bitset<maxN> visited;
    list<int> q;
    int node,count = 0,pages = 1;
    bool not_found = true;
    q.push_back(1);
    visited[1] = 1;
    q.push_back(INF);
    while(q.size() > 0){
        node = q.front();
        q.pop_front();
        if (node == INF){
            if(not_found){
                count += 1;
                q.push_back(INF);
            }
            continue;
        }
        for (int i=0;i<b[node].size();i++){
            if (b[node][i] == -1){
                count += int(not_found);
                not_found = false;
                continue;
            }

            if (!visited[b[node][i]]){
                visited[b[node][i]] = 1;
                pages += 1;
                q.push_back(b[node][i]);
            }
        }
    }
    if (pages == n) cout << 'Y';
    else cout << 'N';
    cout << '\n' << count << '\n';
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> m;
        if (m){
            for (int j=0;j<m;j++){
            cin >> p;
            b[i+1].push_back(p);
            }   
        }
        else b[i+1].push_back(-1);
    }
    bfs();
}