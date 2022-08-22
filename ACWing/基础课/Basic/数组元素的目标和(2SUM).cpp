/*

two pointers

pointer a at beginning at A, and b at end of B
a can only increment, b can only decrement

at the beginning, a is at smallest, so if A[a] + B[b] > K, b must decrease
if A[a] + B[b] < K, a must increase

probably can be proven using induction, but follow recursive logic

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5, INF = 1e9;
int N, M, K;
int A[maxN], B[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<M;i++) cin >> B[i];
    int a = 0, b = M-1;
    while (a < N && b > -1){
        int sum = A[a] + B[b];
        if (sum == K){
            cout << a << ' ' << b << '\n';
            return 0;
        }
        if (sum > K) b -= 1;
        else a += 1;
    }
    return 0;
}