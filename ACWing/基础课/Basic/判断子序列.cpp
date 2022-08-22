/*

two pointers

i on A, and j on B
move j through B and check if B[j] = A[i]
basically checking if the letters of A appear in B in that given order

if i reaches the end before j, output yes, else no

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5, INF = 1e9;
int N, M;
int A[maxN], B[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<M;i++) cin >> B[i];

    int a = 0, b = 0;
    for (b;b<M;b++){
        if (A[a] == B[b]) a += 1;
        // condition needs to have order: if a == N was first,
        // it would miss if a turned N on the last loop
        if (a == N){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}