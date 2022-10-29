/*

suppose the cows are ordered as such:

w1 s1
w2 s2

...

wi si
w(i + 1) s(i + 1)

...

wn sn

with cow n on the bottom 

consider what would happen if we swap cows i and i + 1

cow          risk val before                          after

i          w1 + w2 ... + wi-1 - si           w1 + w2 ... + wi-1 + wi+1 - si

i + 1      w1 + w2 ... + wi-1 + wi - si+1    w1 + w2 ... + wi-1 - si+1

ideally, since we want to reduce the maximum, we could like the max(before) > max(after)

since we are comparing these four values, we can subtract w1 + w2 ... + wi-1 from all of them

before      after

- si         wi+1 - si

wi - si+1    - si+1

we want the value of max(- si, wi - si+1, wi+1 - si, - si+1) to equal one of the values from before, as that would mean that the maximum was reduced

notice how wi+1 - si > - si and wi - si+1 > - si+1 will always be true. 
This means that  max(- si, wi - si+1, wi+1 - si, - si+1) = max(wi+1 - si, wi - si+1), so we are only comparing those values.
thus, for the maximum to be reduced, it must mean that wi+1 - si < wi - si+1
after rearrangement, we get:

    wi+1 + si+1 < wi + si

thus, the maximum is reduced after the swap only if the above equation holds true

hence, the maximum will be at its minimum when w1 + s1 < w2 + s2 < ... < wn + sn
(literally bubble sorting it is proof)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
ar<ll, 2> arr[maxN];

bool comp(ar<ll, 2> &a, ar<ll, 2> &b){
    return a[0] + a[1] > b[0] + b[1];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i][0] >> arr[i][1];
    sort(arr, arr + N, comp);

    ll sum = 0, res = -INF;
    for (int i=N-1;i>=0;i--){
        res = max(res, sum - arr[i][1]);
        sum += arr[i][0];
    }

    cout << res << '\n';

    return 0;
}