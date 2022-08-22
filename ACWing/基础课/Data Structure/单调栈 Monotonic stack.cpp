/*

monotonic stack, classic problem

the O(N*N) brute force method would be:

for (int i=0;i<N;i++){
    for (int j=i-1;j>=0;j--){
        if (a[j] < a[i]){
            cout << a[j] << '\n';
            break;
        }
    }
}

however, notice that some elements will never appear as an answer

suppose:
1. a[x] > a[y], and
2. x < y

because a[y] is smaller AND further ahead in the array, it renders a[x] useless and thus effectively non-existent

which means that a[x] can be delete without impacting future answers

hence, as we iterate i, we can store the processed elements into a stack
and with the logic above, the elements will be stored in monotonically increasing order, in terms of both value and position

whenever we process a new element, we simply pop the stack until the top element is smaller than the new one, which is our answer
the new element can then be pushed into the stack and replace all the ones that were poped out, since it satisfies a[x] > a[y] and x < y


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
vector<int> stk;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        // if it reaches the bottom of the stack, there is no smaller element in front of a
        // also, >= and not >, because the answer has to be strickly less than a
        while (stk.size() > 0 && stk.back() >=   a) stk.pop_back();
        if (stk.empty()) cout << -1 << ' ';
        else cout << stk.back() << ' ';
        stk.push_back(a);
    }
    return 0;
}