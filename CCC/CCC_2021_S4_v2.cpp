// it can be proven an optinmal route is always consisted of riding a prefix of subway trains and 
// then get off and reach n with only walkways
// since this is a query-type question, always compute all needed data beforehand instead of repeatedly doing so
// (good thing to do for all problems with what seems like repetitions of computation)

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 2e5 + 1;
const int INF = 1e9;

int n,w,d,sub[maxN],dis[maxN];
vector<int> g[maxN];
bool visited[maxN];
multiset<int> tdis;

void solve(){
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while(q.size()){
        int node = q.front();
        q.pop();
        for (int v:g[node]){
            if(!visited[v]){
                visited[v] = true;
                dis[v] = 1 + dis[node];
                q.push(v);
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> w >> d;
    for (int i=0;i<w;i++){
        // construct graph, since it is directed, need to reverse edges to find mindist from n
        int a,b; cin >> a >> b;
        g[b].push_back(a);
    }
    // index i is the time the train reaches station si
    for (int i=0;i<n;i++) cin >> sub[i];
    // calculate distance from n to all other n-1 nodes
    for (int i=1;i<n+1;i++) dis[i] = INF;
    dis[n] = 0;
    solve();
    for (int i=0;i<n;i++){
        tdis.insert(i+dis[sub[i]]);
        // multiset is used because:
        // 1. it is ordered
        // 2. it allows multiple elements (which is needed) 
        // 3. allows updating of specific-valued elements (pqueue can't do that)
    }
    // process d queries and update the total
    for (int i=0;i<d;i++){
        int a,b; cin >> a >> b;
        a--,b--;
        //time it takes to arrive at a using sub + time it takes to walk from a to n
        //also use find first, as that grabs the specific iterator, or else all a's will be deleted, which is just wrong
        tdis.erase(tdis.find(a+dis[sub[a]]));tdis.erase(tdis.find(b+dis[sub[b]]));
        swap(sub[a],sub[b]);
        tdis.insert(a+dis[sub[a]]);tdis.insert(b+dis[sub[b]]);

        cout << *tdis.begin() << '\n';
    }
    return 0;
}