/*

notice that N is way to big to try any brute forcing with the actual size of the square
also notice how T <= 100. This hints towards a solution whoes time complexity
is only dependant on the number of trees present. 

next, realize that the optimal square will always have one pair of its opposite edges stuck between
a wall and a tree, or two trees. 

example:

 ------------
 |          |
*|          |
 |          |*
 |          |
 ------------

This can be proven, as if not, it means that the square can expand more, which contradicts that fact
that it is the largest square.

the produces a O(N^3) soluion, in which we iterate through every pair of trees are compute the
size of the square that can be placed between the two trees.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,T;
ar<int,2> arr[maxN];

int com(int a, int b, int c, int d){
    // returns size of pool between (a,b) and (c,d), or return -1 if it doesn't exist
    // the pool could be stuck between two trees horizontally or vertically
    // by swaping the x,y coordinates, we can handle both situation 
    // with the same code
    bool sw = 0;
    if (abs(b-d) > abs(a-c)) sw = 1;
    if (sw) swap(a,b), swap(c,d);
    // since the pool has to be completely stuck between two trees,
    // its size is the difference - 1 (excluding the two ends)
    int size = abs(a-c) - 1;
    int ub = min(min(b,d) + size,N), lb = max(max(b,d) - size,1);
    for (int i=0;i<T;i++){
        int x = arr[i][0], y = arr[i][1];
        if (sw) swap(x,y);
        if (min(a,c) < x&&x < max(a,c)){
            if (min(b,d) < y&&y < max(b,d)) return -1;
            if (y <= min(b,d)) lb = max(lb,y+1);
            if (y >= max(b,d)) ub = min(ub,y-1);
        }
    }
    if (ub - lb + 1 >= size) return size;
    else return -1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> T;
    for (int i=0;i<T;i++) cin >> arr[i][0] >> arr[i][1];
    int msf = 0;
    for (int i=0;i<T;i++){
        int a = arr[i][0], b = arr[i][1];
        msf = max(msf, com(a,b,a,0)); 
        msf = max(msf, com(a,b,0,b));
        msf = max(msf, com(a,b,a,N+1));
        msf = max(msf, com(a,b,N+1,b));
        for (int j=i+1;j<T;j++){
            int c = arr[j][0], d = arr[j][1];
            // first check between the tree and the surrounding walls
            msf = max(msf, com(a,b,c,d));
        }
    }
    cout << msf << '\n';
    return 0;
}