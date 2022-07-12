/*

I liked the way I wrote this problem, so I kept it. 

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN], og[maxN];
unordered_map<int, int> pos;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> og[i];
    memcpy(arr, og, sizeof(og));
    sort(og, og + N);
    for (int i=0;i<N;i++) pos[og[i]] = i;

    // default positions incase the array is already sorted
    int cnt = 0, ed = 0, st = 0;
    for (int i=0;i<N;i++){
        if (arr[i] != og[i]){
            st = i, ed = pos[arr[i]];
            for (int j=0;j<=ed-i;j++){
                if (arr[st + j] != og[ed - j]){
                    cout << "no\n";
                    return 0;
                }
            }
            cnt += 1;
            i = ed;
        }
    }
    if (cnt > 1) cout << "no\n";
    else cout << "yes\n" << st + 1 << ' ' << ed + 1 << '\n';
    return 0;
}