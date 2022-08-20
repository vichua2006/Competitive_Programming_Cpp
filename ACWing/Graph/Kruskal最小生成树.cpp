/*

really nothing to say here, standard kruskal's 

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M;
int s[maxN], l[maxN];
ar<int, 3> arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int find(int x){
    if (x != l[x]) l[x] = find(l[x]);
    return l[x];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    int cnt = 0, sum = 0;
    for (int i=0;i<N+1;i++) s[i] = 1, l[i] = i;
    for (int i=0;i<M;i++){
        int a, b, c; cin >> a >> b >> c;
        arr[i] = {c, a, b};
    }

    sort(arr, arr + M);
    for (int i=0;i<M;i++){
        int c = arr[i][0], a = arr[i][1], b = arr[i][2];
        a = find(a), b = find(b);
        if (a != b){
            if (s[a] < s[b]) swap(a, b);
            l[b] = a;
            s[a] += s[b];
            cnt += 1, sum += c;
        }
    }

    if (cnt == N - 1) cout << sum << '\n';
    else cout << "impossible\n";

    return 0;
}