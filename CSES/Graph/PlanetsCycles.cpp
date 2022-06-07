//cycle finding in successor graph, probably easier than dfs?
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
// here, dis[i] denotes the number of steps it takes, starting at i, 
// to arrive at a planet that has already been visited
// visited: 0 is undiscovered, 1 is discovered, 2 is processed
int N,f[maxN],dis[maxN],visited[maxN];
vector<int> p,cycle;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void find_cycle(int curr){
    if (visited[curr] == 1){
        // trace back to another appearence of curr
        int s = curr;
        cycle.push_back(s);
        while(p.back()!=s) cycle.push_back(p.back()),p.pop_back();
        for (int a: cycle) dis[a] = cycle.size();
        return;
    }
    // similar to tp sort, is means that it's not actually a cycle
    if (visited[curr] == 2) return;
    visited[curr] = 1;
    p.push_back(curr);
    find_cycle(f[curr]);
    visited[curr] = 2;
    return;
}

void dfs(int curr){
    // if it reaches a loop, it would then take 1 + the length of the loop
    if (dis[f[curr]]){
        dis[curr] = 1 + dis[f[curr]];
        return;
    }
    dfs(f[curr]);
    dis[curr] = 1 + dis[f[curr]];
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> f[i];
    for (int i=1;i<N+1;i++){
        p.clear(),cycle.clear();
        if (visited[i] == 0) find_cycle(i);
    }
    for (int i=1;i<N+1;i++){
        if (dis[i] == 0) dfs(i);
    }
    for (int i=1;i<N+1;i++) cout << dis[i] << (i == N?'\n':' ');
    return 0;
}