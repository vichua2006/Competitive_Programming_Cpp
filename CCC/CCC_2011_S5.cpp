// bfs complete search
// ugh, TLE and almost MLE, rewrite binary operation version later
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
vector<bool> l;
map<vector<bool>,int> d;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

bool nall(vector<bool> &v){
    bool temp = 0;
    for (int i=0;i<v.size();i++) temp |= v[i];
    return !temp;
}

vector<bool> nstate(vector<bool> v,int idx){
    v[idx] = 1;
    int a = 0,b = 0;
    while(a<N){
        for (b=a;b<N&&v[b];b++);
        if (b-a>=4){
            for (int i=a;i<=b;i++) v[i] = 0;
        }
        a = b+1;
    }
    return v;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    l.resize(N,0);
    for (int i=0;i<N;i++){
        bool a; cin >> a;
        l[i] = a;
    }
    queue<vector<bool>> q;
    q.push(l); d[l] = 0;
    while(q.size()){
        vector<bool> node = q.front(); q.pop();
        for (int i=0;i<N;i++){
            if (!node[i]){
                vector<bool> nnode = nstate(node,i);
                if (d.find(nnode)==d.end()){
                    if (nall(nnode)){
                        cout << d[node] + 1 << '\n';
                        return 0;
                    }
                    d[nnode] = d[node] + 1;
                    q.push(nnode);
                }
            }
        }
    }
    return 0;
}