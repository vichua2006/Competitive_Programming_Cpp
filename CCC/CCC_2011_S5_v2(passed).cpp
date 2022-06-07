/*

instead of bool vectors, I straight up used numbers
this allows for a bool array visited, which is so much freaking faster than
a hash table

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1<<24 + 1,maxK = 201,INF = 1e9,MOD = 1e9+7;
int N,s = 0;
bool visited[maxN];

int upd(int x){
    int a = 0,b = 0;
    while (a<N){
        for (b=a;b<N&&(x&(1<<b));b++);
        // b will be incremented one more than the last light on, so it's b-1;
        // b-1-a+1 = b-a;
        if (b-a>=4){
            for (int i=a;i<b;i++){
                x ^= (1<<i);
            }
        }
        a = b+1;
    }
    return x;
}

int bfs(){
    queue<int> q;
    int mk = INF,cnt = 0;
    visited[s] = 1;
    q.push(s);q.push(mk);
    while (q.size()){
        int v = q.front();q.pop();
        if (v==0) return cnt;
        if (v==INF){
            cnt += 1;
            q.push(v);
            continue;
        }
        for (int i=0;i<N;i++){
            if (!(v&(1<<i))){
                int nv = v^(1<<i);
                nv = upd(nv);
                if (!visited[nv]){
                    visited[nv] = 1;
                    q.push(nv);
                }
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++){
        bool a; cin >> a;
        if (a) s ^= 1<<i; 
    }
    cout << bfs() << '\n';
    return 0;
}