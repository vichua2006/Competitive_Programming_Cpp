/*

another complete search type problem, this one is basically searching all the possible ways these numbers could be grouped and picking the one that
uses the least number of groups

each dfs call represents a different grouping. It is worth noting that instead of iterating each number and brute forcing which group it goes in, this
solution iterates each group and brute force what numbers would go into the current group. Since each situation in the first method can correspond to the second, 
they are equivalent and correct.

one thing to realize is that a new group should not be made unless none of the currently available numbers can be placed into the current group, as
it can be proven that placing a number in a new group when it did not have to be only worsens the solution.

another thing to realize that [1, 2, 3] is the same thing as [2, 1, 3] or any permutation of those. We are not iterating all permutations, but only all
combinations to speed up the solution

was TLEing because maxN was set to 1e6 instead of 10. Careful next time

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 10 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, ans;
int arr[maxN];
vector<int> g[maxN];
bool vis[maxN];

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

bool e(int x, int y){
    for (int a: g[x]){
        if (gcd(arr[a], arr[y]) > 1) return false;
    }

    return true;
}

void dfs(int curr, int n, int s){
    // if the number of groups used is already more than the current most optimal answer, then this branch can be pruned
    if (curr >= ans) return;
    if (n == N){
        ans = min(ans, curr);
        return;
    }

    bool newg = true;
    // for each i, we consider the possibilities if: 1. we choose i (if we can), 2. we don't choose i
    for (int i=s;i<N;i++){
        // i is not used and coprime with all other numbers in the current group
        if (!vis[i] && e(curr, i)){
            // don't need new group
            newg = false;

            g[curr].push_back(i);
            vis[i] = 1;
            // start at i because we are only going unordered arrangements
            dfs(curr, n + 1, i + 1);
            vis[i] = 0;
            g[curr].pop_back();
        }
    }

    if (newg) dfs(curr + 1, n, 0);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    ans = N;
    for (int i=0;i<N;i++) cin >> arr[i];

    dfs(1, 0, 0);

    cout << ans << '\n';

    return 0;
}