/*

for any Ai that satisfies the given gcd conditions, it must be 
AT LEAST the lcm of the required gcds (if A2 needs to have a gcd of 2 and 3, then
it needs to be at least 6, lcm of 2,3)

since there are only 16 possible gcd values, be can record the requirement for 
every Ai and compute their respective valid values

because the requirements are given if the form of [a,b] intervals, difference array should be used to
reduce complexity. 16 difference arrays. the actual values could be summed after
we read in all the requirements

then we have to check through them once more to make sure that it is correct
(the values being lcm guareentees the correctness--it is the bare minimum to satisfy 
the required gcd, so if such a sequence is invalid, then no such sequence exist)

the checking can then be done with a gcd segment tree
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,K=1,dif[maxN][17],pre[17];
ar<int,3> req[maxN];
vector<int> tree;

int gcd(int x,int y){
    // refer to number theory gcd section of ZJZ math class
    // extension of gcd(a1,a2) = gcd(a1,a2-a1)
    return y ? gcd(y,x%y) : x;
}

int qry(int a,int b){
    a += (K-1),b += (K-1);
    int res = 0;
    while (a<=b){
        if (a%2==1) res = gcd(res,tree[a++]);
        if (b%2==0) res = gcd(res,tree[b--]);
        a/=2,b/=2;
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    while (K<N) K *= 2;
    tree.resize(2*K);
    for (int i=0;i<M;i++){
        int a,b,c; cin >> a >> b >> c;
        dif[a][c] += 1;
        if (b+1<=N) dif[b+1][c] -= 1;
        req[i] = {a,b,c};
    }
    for (int i=1;i<N+1;i++){
        int lcm = 1;
        for (int j=1;j<=16;j++){
            pre[j] += dif[i][j];
            if (pre[j]!=0){
                // if there is an requirement of gcd j on Ai, we update the lcm for that Ai
                // gcd(a,b)*lcm(a,b) = a*b
                // -> lcm(a,b) = a*b/gcd(a,b)
                // -> new lcm = (old lcm*new number)/gcd(old lcm, new number)
                lcm = (lcm*j)/gcd(lcm,j);
            }
        }
        // directly write the value into the segt tree
        tree[i+K-1] = lcm;
    }
    // gcd(a,b,c) = gcd(gcd(a,b),gcd(b,c)), or in this case, gcd(a,b,c,d) = gcd(gcd(a,b),gcd(c,d))
    for (int i=K-1;i>=1;i--) tree[i] = gcd(tree[2*i],tree[2*i+1]);
    for (int i=0;i<M;i++){
        int a = req[i][0],b = req[i][1],c = req[i][2];
        if (qry(a,b)!=c){
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i=1;i<N+1;i++) cout << tree[i+K-1] << (i==N?'\n':' ');
    return 0;
}