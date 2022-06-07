/*

two pointers, keep going until encountering a
repeated node, then remove all songs up to the repeated song
from the second pointer

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN];
set<int> s;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    int res = 0;
    for (int i=0;i<N;i++) cin >> arr[i];
    for (int i=0,j=0;i<N;i++){
        if (s.count(arr[i])){
            for (j;arr[j]!=arr[i];j++) s.erase(arr[j]);
            s.erase(arr[j]), j += 1;
        }
        s.insert(arr[i]);
        res = max(res,i-j+1);
    }
    cout << res << '\n';
    return 0;
}