// original idea was that I would keep tract of all increasing subsequences (that increases by one)
// and then count how many I would end up with
// e.g. if I first encounter 5, I would put 5 in the first vector, and 
// somehow record that, if 6 was ever found, it would go into the same vector as five
// then, if I find 3 next, I place it in a new vector as it is now longer in a increasing sequence with 5
// turns out, I only need the fact that "there are x vectors" and not what's in them, so it could be simplified
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N;
// arr[i] denotes the existence of a increasing subsequence that begins with i
bool arr[maxN];
// d[i] denotes that which subsequence i would belong in
unordered_map<int,int> d;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) d[i] = i;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        // either starts a new subsequence or gets placed in a pre-existing one
        arr[d[a]] = true;
        // adjusts the next element in the sequence 
        // e.g. if 5 was found, it would be put with, say, 2,3,4
        // in this case, d[5] = 2, because 5 is the next element after 4
        // then, since five is in, the next element would be 6, so d[6] = 2 (d[5])
        d[a+1] = d[a]; 
    }
    int ans = 0;
    for (int i=1;i<N+1;i++) ans += arr[i];
    cout << ans << '\n';
    return 0;
}