/*

disgusting, took me 1.5 hours for this shit
basically realize that if we need any -1s at all, we only need one to do it

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M, A, B;
ar<int,2> arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> A >> B;
    // last negative 1
    int lng = -1;
    for (int i=0;i<M;i++){
        cin >> arr[i][0];
        if (arr[i][0] < 0) arr[i][1] = -1, lng = i;
        else cin >> arr[i][1];
    }

    // position from start, position from end
    // representing where the shell would end up at starting at A assuming it was not affected by any of the -1, 
    // and where the shell needs to be to end up at B assuming it was not affected by any of the -1.
    int ps = A, pe = B;
    for (int i=0;i<lng;i++){
        if (arr[i][0] == ps){
            ps = arr[i][1];
            continue;
        }
        if (arr[i][1] == ps){
            ps = arr[i][0];
            continue;
        }
    }

    for (int i=M-1;i>lng;i--){
        if (arr[i][0] == pe){
            pe = arr[i][1];
            continue;
        }
        if (arr[i][1] == pe){
            pe = arr[i][0];
            continue;
        }
    }

    // move the shell from where it is to where it needs to be
    if (ps != pe) arr[lng] = {ps, pe};
    // simulate the process and fill in any remaining -1 (arbitrary value as long as they remain within [1, N]
    // and does not move the actual schell)
    int p = A;
    for (int i=0;i<M;i++){
        for (int j=0;j<2;j++){
            if (arr[i][j] == p){
                p = arr[i][j^1];
                break;
            }
        }
        if (arr[i][0] == -1){
            if (p == N) arr[i] = {p - 1, p -2};
            if (p == 1) arr[i] = {p + 1, p + 2};
            if (p != 1 && p != N) arr[i] = {p - 1, p + 1};
        }
    }
    for (int i=0;i<M;i++) cout << arr[i][0] << ' ' << arr[i][1] << '\n';
    return 0;
}