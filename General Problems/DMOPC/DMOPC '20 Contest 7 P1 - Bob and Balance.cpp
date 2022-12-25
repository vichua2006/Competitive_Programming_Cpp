/*

suppose there was a mass that appeared x > N times. By pigeon hole principle (or if you just think about it), there are at most N - x possible pairs
if there are no mass that appear over N times, then there always be N pairs

specifically, we can sort the masses in an non-decreasing order and realize that if no mass that appear more than N times, it means that there will never
be a segment of length greater than N, which means that i and i + N will always be different

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN], idx[maxN];
bool vis[maxN];

bool comp(int a, int b){
    return arr[a] < arr[b];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<2*N;i++) cin >> arr[i], idx[i] = i;

    // sort the indices by their arr[i] value for easy match up and output
    sort(idx, idx + 2 * N, comp);

    int cnt = 0;
    vector<ar<int, 2>> ans;
    for (int i=0;i<N;i++){
        if (arr[idx[i]] ^ arr[idx[i + N]]) cnt += 1;
        ans.push_back({idx[i], idx[i + N]});
    }

    cout << cnt << '\n';
    for (auto a: ans) cout << a[0] + 1 << ' ' << a[1] + 1 << '\n';

    return 0;
}