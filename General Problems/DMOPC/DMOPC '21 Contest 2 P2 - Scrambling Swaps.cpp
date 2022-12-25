/*

a mapping of where each number should be at should be maintained at a low time complexity so that the output queries can be 
processed at O(N) instead of O(N^2), which would TLE

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 3e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, Q;
// element on idx i, and idx of element i
int arr[maxN], pte[maxN], etp[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=1;i<N+1;i++) pte[i] = i, etp[i] = i;
    for (int i=0;i<Q;i++){
        char a; cin >> a;
        if (a == 'B' || a == 'E'){
            int b, c; cin >> b >> c;
            // swap
            // this swapity swap logic can go eat shit. comments will be written another time


            // essentially, we will be swaping the sequence in reverse order. Thus, "front" will be refering to back, and vice versa
            // let us call the elements a1, a2, ... , an
            // if the pair (i, j) is added to the front, then all we need to do is to swap the elements in position i and j
            // it is inserted to the back however, we need to find where ai and aj are currently at, and then swap them, to 
            // pretend as if they were swapped for the whole time
            // to do that, the etp[i] array denotes the current position of ai, which has its own update logic
            if (a == 'B') swap(pte[b], pte[c]), swap(etp[pte[b]], etp[pte[c]]);
            else swap(etp[b], etp[c]), swap(pte[etp[b]], pte[etp[c]]);
        } else {
            for (int i=1;i<N+1;i++) cin >> arr[i];
            for (int i=1;i<N+1;i++) cout << arr[pte[i]] << (i == N ? '\n' : ' ');
        }
    }

    return 0;
}