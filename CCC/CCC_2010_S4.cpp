// restating: given a weighted, undirected graph, calculate the minimum sum of weights of edges
// that when removed, connects all enclosed area
// suppose there are two polygons (two enclosed areas) that share an edge, A and B.
// therefore, to reach A from B by acrossing the shared edge e, it would cost the weigth of e
// this could be modeled as an edge from area A to B with weight e. The question then
// becomes to find the minimum spanning tree of the new graph
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e2 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,l[maxN],s[maxN],in[maxN];
vector<ar<int,3>> elist1,elist2;
map<ar<int,3>,vector<int>> d;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int find(int x){
    if (l[x]!=x) l[x] = find(l[x]);
    return l[x];
}

int kruskal(vector<ar<int,3>> &elist){
    int ans = 0;
    for (ar<int,3> edge:elist){
        int w = edge[0],a = edge[1],b = edge[2];
        a = find(a), b = find(b);
        if (a!=b){
            if (s[a] < s[b]) swap(a,b);
            l[b] = a;
            s[a] += s[b];
            ans += w;
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    // the outside area will be considered as node 0
    for (int i=1;i<N+1;i++){
        int ep; cin >> ep;
        for (int j=0;j<ep;j++) cin >> in[j];
        for (int j=0;j<ep;j++){
            int w; cin >> w;
            // weight, smaller node, larger node; prevents things like (w,a,b) and (w,b,a)
            // node i (area) is connected to this fence; there should be at most to elements for each key
            d[{w,min(in[j],in[(j+1==ep?0:j+1)]),max(in[j],in[(j+1==ep?0:j+1)])}].push_back(i);
        }
    }
    for (auto a:d){
        int w = a.first[0];
        vector<int> &nodes = a.second;
        // if there is no second area, then it is connected to the outer area;
        int n1 = nodes[0],n2 = (nodes.size()==1?0:nodes[1]);
        elist1.push_back({w,n1,n2});
        if (n1!=0&&n2!=0) elist2.push_back({w,n1,n2});
    }
    sort(elist1.begin(),elist1.end());
    sort(elist2.begin(),elist2.end());
    int ans1 = 0, ans2 = 0;
    // okay, so there needs to be some special treate=ment to node 0
    // sometimes we are forced to connect to the outside, but other times we don't
    // hence,I will compute two MST: one with 0 and other without, and pick the smaller of the two answers
    for (int i=1;i<N+1;i++) l[i] = i, s[i] = 1;
    ans1 = kruskal(elist1);
    for (int i=1;i<N+1;i++) l[i] = i, s[i] = 1;
    ans2 = kruskal(elist2);
    cout << min(ans1,ans2) << '\n';
    return 0;
}