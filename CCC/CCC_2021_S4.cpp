//trains basically act as temperary edges, and since it is guarenteed that you can reach the n station in n units
//(just board the train and ride through every station)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

vector<int> g[200001];
bool visited[200001],t_visited[200001];
int n,w,d,t[200000];
pair<int,int> s[200000];

int bfs(){
    for (int i=0;i<n;i++){
        visited[i] = false;
        t_visited[i] = false;
    }
    list<int> q; int count = 0;
    q.push_back(1);
    q.push_back(INF);

    while (q.size()>1){
        int node = q.front();
        q.pop_front();
        if (node == INF){
            count += 1;
            // train visited station count
            t_visited[count] = true;
            q.push_back(INF);
            continue;
        }
        if (node == n){
            return count;
        }
        if (!t_visited[node]){
            //decides if it is possible to board the train
            if ((t[count] == node) && (count <= n-1)){
                q.push_back(t[count+1]);
            }
            else{
                q.push_back(node);
            }
        }
        if (!visited[node]){
            for (int v: g[node]){
                if (!visited[v]){
                    q.push_back(v);
                }
            }
        }
        visited[node] = true;
    }
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> w >> d;
    for (int i=0;i<w;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i=0;i<n;i++){
        cin >> t[i];
    }
    for (int i=0;i<d;i++){
        cin >> s[i].first >> s[i].second;
    }

    for (int i=0;i<d;i++){
        swap(t[s[i].first-1],t[s[i].second-1]);
        cout << bfs() << '\n';
    }
    return 0;
}