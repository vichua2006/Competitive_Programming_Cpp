/*
CCC prep

binary search on the hose distance

for each distance, test how many hydrants in takes to cover for all houses, if it exceeds M, a += 1, else b -= 1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e3+1,INF = 1e9;
int N,M,D = 1e6;
int arr[maxN];
bool visited[maxN];

int dist(int a,int b){
    // distance from a to b
    return b >= a ? b-a : b+D-a;
}

int g(int k,int l,int r){
    int cnt = 0;
    for (int oi=l;oi<=r;oi++){
        int i = oi%N;
        if (!visited[i]){
            // set a hydrant with hose of length k, k units in front of house
            cnt += 1;
            for (int oj=i;oj<=r;oj++){
                int j = oj%N;
                if (dist(arr[i],arr[j]) <= 2*k){
                    visited[j] = 1;
                    continue;
                }
                break;
            }
        }
    }
    return cnt;
}

bool f(int k){
    // to ensure correct answer, we have to start at every house position
    int d = INF;
    for (int i=0;i<N;i++){
        memset(visited,0,sizeof(visited));
        d = min(g(k,i,N-1+i),d);
    }
    return (d<=M);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i];
    cin >> M;
    sort(arr,arr+N);
    int a = 0,b = D,p;
    // binary search for the optimal hose length
    while (a < b-1){
        p = (a+b)/2;
        if (f(p)) b = p;
        else a = p+1;
    }
    if (f(a)) cout << a << '\n';
    else cout << b << '\n';
    return 0;
}