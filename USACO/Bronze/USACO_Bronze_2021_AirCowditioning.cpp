// wow I am surprised that I actually figured out this question during the contest
// so, actually simulating the range update was out of the question, since it would be O(n^2) with n <= 5e5
// thanks to reading and smashing my head against the range query section of CSES, I knew that difference arrays must be
// used to handle range updates
// suppose we have the desired array: t1,t2,t3...tn
// and the current array: a1,a2,a3...an
// since the prefix sum array of a difference array is the original array,
// if the difference array of t and a were the same, it would also mean that the actual arrays are also the same
// we can then obtain: (t1-0)-(a1-0), (t1-t2)-(a2-a1), .... ,(tn-t(n-1))-(an-a(n-1)) (subtract the two difference arrays)
// each step, we can increase one element by 1 and decrease another by 1, what is the minimum steps to get all elements equal 0?
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5 + 1, INF = 1e9, MOD = 1e9 + 7;
// temp and arr are all difference arrays
int N,temp1[maxN],temp[maxN],arr1[maxN],arr[maxN],dif[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++){
        cin >> temp1[i];
        temp[i] = temp1[i] - temp1[i-1];
    }
    for (int i=1;i<N+1;i++){
        cin >> arr1[i];
        arr[i] = arr1[i] - arr1[i-1];
    }
    for (int i=1;i<N+1;i++){
        dif[i] = temp[i]-arr[i];
    }
    //two pointers, a points to positives, b points to negatives
    // actually, I should have thought a bit more about it: I just needed to add the positive together and the negatives together
    // and print the larger one
    ll pos = 0, neg = 0;
    for (int i=1;i<N+1;i++){
        if (dif[i] > 0) pos += dif[i];
        if (dif[i] < 0) neg += abs(dif[i]);
    }
    cout << max(pos,neg) << '\n';
    return 0;
}