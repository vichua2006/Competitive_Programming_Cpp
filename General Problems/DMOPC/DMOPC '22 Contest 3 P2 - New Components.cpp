/*

first, make the observation that a graph constructed in this form consists of many loops
to create more components in a loop, we have to disconnect nodes
the most certain way to do that is to "erase" edges; consider x in set S, let Px be the node it leads to, and Xp be the node that leads to x
since we need to redirect x, we can simply redirect x to Xp, effectively making the edge useless, and thus "erased" 
(and under this situation, Xp does not need to be redirected, since if x is able to connect to it, then Xp is not in S)

in a cycle, if we erase D edges, we obtain D - 1 new components*

in the case where Xp is in S, then x cannot further "disconnect" the loop, as it will be forced to connect to some component (including the one that it is in)
this does not affect the answer; x will not "connect" different components, because, since Xp is in S, the edge Xp -> x will be redirected as well, so x
will merely belong in that component as a "leaf node" and not do anything.

originally, the answer is C, the number of components
thus, for each cycle that contains at least one x in S, we count the number of removable edges, Di, in cycle i, and add Di - 1 to the final answer
since we -1 for each affected cycle, we can instead count number of affected cycles, and subtract it from C + D_total


* (after removing one edge, it becomes a tree, and in tree,
every edge removed yields a new component.
and both new and old components are also trees, so this could be applied recursively

however, the special case is that all nodes in a cycle are in S and there are thus 0 removable edges
this only happens all nodes do not form a single cycle, and results in D = 0. Thus D - 1 = -1, which is also somehow correct)

I don't understand the intuition behind this problem
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N, Q;
// next node, previous node, comp[i] = component i belongs to
int ne[maxN], pre[maxN], comp[maxN];
bool inS[maxN], act[maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> Q;
    for (int i=1;i<N+1;i++) cin >> ne[i], pre[ne[i]] = i;

    // count all components
    int cnt = 0;
    for (int i=1;i<N+1;i++){
        int node = i;
        if (comp[node] == 0){
            cnt ++ ;
            while (comp[node] == 0) comp[node] = cnt, node = ne[node];
        }
    }

    vector<int> S, affected;
    for (int i=0;i<Q;i++){
        // wow TLE with hash maps, are they really that slow?
        S.clear(), affected.clear();
        int ssize; cin >> ssize;
        for (int j=0;j<ssize;j++){
            int a; cin >> a;
            S.push_back(a);
            inS[a] = 1;
        }

        int D = 0;
        for (int j : S){
            if (!act[comp[j]]){
                affected.push_back(comp[j]);
                act[comp[j]] = 1;
            }
            if (!inS[pre[j]]) D += 1;
        }     

        cout << cnt + D - affected.size() << '\n';

        for (auto s : S) inS[s] = 0;
        for (auto a : affected) act[a] = 0; 
    }

    return 0;
}