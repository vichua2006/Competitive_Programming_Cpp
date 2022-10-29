/*

this problem, is actually a range dp problem

since the in-order of the binary tree is 1, 2, ... , n, its root node could be any one of 1 ~ n

suppose the optimal root of the tree is k, then all the nodes from 1 to k - 1 will belong to the left subtree of k, and all
nodes from k + 1 to n will belong to the right subtree, and those two ranges are completely independent of each other.

to achieve the overall maximum, each subtree must also achieve its maximum

from there, it becomes a recursive process.
let val[i] denote the value of node i, and let dp[i][j] denote the maximum value achieved by combining the nodes [i, j]
into a binary tree, with its in-order as i, i + 1, ... , j

therefore, dp[i][j] = max(dp[i][k - 1] * dp[k + 1][j] + val[k]) for all k in [i, j]

the problem also asks for the lexicographically smallest pre-order answer, and output said pre-order
again, this can be done with greedy

suppose dp[i][j] achieves max when it is rooted at k, let g[i][j] denote the root of the binary tree that yields that maximum value
from there, we can just recursively output the roots of the subtrees 

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e2 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int val[maxN];
int dp[maxN][maxN], g[maxN][maxN];

void output(int a, int b){
    if (a == b){
        cout << a << ' ';
        return;
    }
    int r = g[a][b];
    cout << r << ' ';
    if (r == a) output(r + 1, b);
    else if (r == b) output(a, r - 1);
    else {
        output(a, r - 1);
        output(r + 1, b);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> val[i];

    for (int i=1;i<N+1;i++){
        for (int j=i;j;j--){
            if (i == j){
                dp[j][i] = val[i];
                g[j][i] = i;
                continue;
            }
            int v;
            for (int k=j;k<=i;k++){
                if (k == j) v = dp[k + 1][i];
                else if (k == i) v = dp[j][k - 1];
                else v = dp[j][k - 1] * dp[k + 1][i];

                if (v + val[k] > dp[j][i]){
                    dp[j][i] = v + val[k];
                    g[j][i] = k;
                }
            }
        }
    }

    cout << dp[1][N] << '\n';
    output(1, N);

    return 0;
}