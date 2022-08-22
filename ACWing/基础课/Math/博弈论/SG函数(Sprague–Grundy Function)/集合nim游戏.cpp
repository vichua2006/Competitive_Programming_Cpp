/*
define mex({a1, a2, a3,..., an}) as an operation to compute the smallest non-negative number that does not below in the set 

let x be an state of an impartial game, and since states of impartial games from a directly ancyclic graphy, let x be connected to 
y1, y2, y3,..., yk

let the SG values of all the ending positions (all-empty piles in the context of nim) be defined as 0
for any other x, SG(x) = mex({SG(y1), SG(y2),..., SG(yk)})

this gives us the interesting property of:
if SG(x) = 0, then x is a losing position
if SG(x) != 0, then x is a winning position
(see image)

if SG(x) = 0, it means it cannot be turned into another 0 position, and vice versa

suppose there are multiple games (and thus multiple graphs). Let the starting position of each game be s1, s2, s3,..., sk

then if SG(s1) ^ SG(s2) ^...^ SG(sk) = 0, then it is an losing position. Otherwise, it is a winning position
(the proof is very similar to nim)
SG(e1) ^ SG(e2) ^...^ SG(ek) = 0 is the ending position.

for any SG(x1) ^ SG(x2) ^...^ SG(xk) = x != 0,
there must exists an xi such that SG(xi) > SG(xi) ^ x .
Thus, we change xi to yi such that SG(yi) = SG(xi) ^ x (which is always possible)

for any SG(x1) ^ SG(x2) ^...^ SG(xk) = 0, if we change the value SG(xi) to SG(xi)' != SG(xi) in attempt to make the value 0 again,
we will find that SG(xi) = SG(xi)', which is impossible and a contradiction.

following that same nim logic, the proof holds
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e4 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, K;
// memo[i] = SG(i)
int arr[maxN], memo[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int sg(int x){
    // we can use memorized recursion to compute sg(x)
    if (memo[x] != -1) return memo[x];

    unordered_set<int> s;
    for (int i=0;i<K;i++){
        if (x >= arr[i]) s.insert(sg(x - arr[i]));
    }

    int mex;
    for (int i=0;i<maxN;i++){
        if (!s.count(i)){
            mex = i;
            break;
        }
    }

    memo[x] = mex;
    return mex;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> K;
    for (int i=0;i<K;i++) cin >> arr[i];

    cin >> N;
    int res = 0;
    memset(memo, -1, sizeof(memo));
    for (int i=0;i<N;i++){
        int a; cin >> a;
        res ^= sg(a);
    }

    if (res) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}