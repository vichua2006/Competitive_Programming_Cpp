#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M;
vector<string> names;
unordered_map<int,vector<string>> d1;
unordered_map<string,vector<int>> d2;
unordered_map<string,int> dis;
unordered_map<string,bool> visited;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void bfs(){
    queue<string> q;
    q.push("Alice");
    dis["Alice"] = 0;
    visited["Alice"] = true;
    while(q.size()){
        string v = q.front();q.pop();
        for (int orgs:d2[v]){
            for (string u:d1[orgs]){
                if (!visited[u]){
                    visited[u] = true;
                    dis[u] = dis[v]+1;
                    q.push(u);
                }
            }
        }
    }
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    for (int i=1;i<N+1;i++){
        string a; cin >> a;
        names.push_back(a);
        dis[a] = -1;
    }
    for (int i=1;i<M+1;i++){
        int k; cin >> k;
        for (int j=0;j<k;j++){
            string a; cin >> a;
            d1[i].push_back(a),d2[a].push_back(i);
        }
    }
    bfs();
    for (int i=0;i<N;i++) cout << dis[names[i]] << (i==N-1?'\n':' ');
    return 0; 
}