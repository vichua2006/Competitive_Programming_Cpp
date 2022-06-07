/*
Now considering D
basically, we seek to replace an edge in the original MST with an old edge to achieve the same
total weight but with one less day (proved by contradiction, hereinafter known as pbc, it's impossible to achieve a smaller value)
first off, D must be used on the edges with the same weight as the heavest edge, as using it on other may potentially produce a worse result (1)
suppose we try to replace w1 (<= maxW) with an old w2 ( > maxW by ordering of the edge list (old before new, so any old after the largest new will be larger))
by (1), w1 + max(0,maxW - D) = max(0,w2 - D) + maxW (because w2 > maxW,D is used on w2). This equation has to be true, however:

1. since maxW < w2, in cases of D < w2, max(0,maxW - D) will always be less than max(0,w2 - D). So D must >= w2
2. suppose 1. is now holds and max(0,maxW - D) = max(0,w2 - D), we now have w1 <= maxW. to be equal, then w1 must always equal maxW

combining 1. and 2., we get that, for a replacement to be possible:

D must be greater than w2 > maxW (or else it will no longer be the weight of MST)
AND
w1 == maxW, meaning that only edges with the heavest weigth of the current MST will be replaced (and it must be new edge).

hence, we first run a standard kruskal and record the heavest edge.
then we run it a second time, but this time NOT using any of the new edges with the heavest weight.
we try to find any old edge that: 
1. does the same as of the edges with heavest weight (connects the same conponent), and
2. has weight w2 <= D
if such edge exists, we can save on day, so days -= 1;

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N,M,D;
int s[maxN],l[maxN];
vector<ar<int,4>> edges;

int find(int x){
    if (x!=l[x]) l[x] = find(l[x]);
    return l[x];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> D;
    for (int i=0;i<N+1;i++) l[i] = i,s[i] = 1;
    for (int i=1;i<M+1;i++){
        int a,b,c; cin >> a >> b >> c;
        edges.push_back({c,(i>=N),a,b});
    }
    int W = 0,days = 0;
    bool newp = false;
    sort(edges.begin(),edges.end());
    for (auto e:edges){
        int c = e[0],o = e[1],a = e[2],b = e[3];
        a = find(a),b = find(b);
        if (a!=b){
            if (a<b) swap(a,b);
            // new pipe == extra day
            if (o) days += 1,newp = o;
            l[b] = a;
            s[a] += s[b];
            W = max(W,c);
        }
    }
    // last pipe was a new pipe
    if (newp){
        // run it a second time
        for (int i=0;i<N+1;i++) l[i] = i,s[i] = 1;
        for (auto e:edges){
            int c = e[0],o = e[1],a = e[2],b = e[3];
            a = find(a),b = find(b);
            if (a!=b){
                if (a<b) swap(a,b);
                // filter out new pipes with weight == W
                if (c < W||(o==0&&c==W)) l[b] = a,s[a] += s[b];
                // check if satisfies requirement 2. listed in head comment
                else {
                    // is old edge, greater than W, less than or equal to D
                    if (o==0&&c<=D){
                        days -= 1;
                        break;
                    }
                }
            }
        }
    }
    cout << days << '\n';
    return 0;
}