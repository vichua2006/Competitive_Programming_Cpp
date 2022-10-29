/*

this is basically longest non-increasing subdequence + CCC 2017 (or 2014?) - Gates

really nothing to say about the first part, standard dp

the latter can be done by maintaining the last chot made by the ith system
formally, let arr[i] denote the height of the last shot made by the ith system

for any new missle with height k, we look for the smallest arr[i] that is larger than k
and let k be the last shot made by system i
(greedy, you only yield potentially worst result if you pick larger arr[i])

if such any i doesn't exist, we simply append it to the end of arr, and it becomes a new system
(realize that such a method results in a increasing sequence, which is convenient for computing the smallest
arr[i] that is larger than k)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int dp[maxN], val[maxN];
int arr[maxN], cnt = 0;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    int a, i = 1, msf = 0;
    while (cin >> a){
        val[i] = a;
        dp[i] = 1;
        for (int j=1;j<i;j++){
            if (val[j] >= val[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        msf = max(msf, dp[i]);
        bool flag = 1;
        for (int i=0;i<cnt;i++){
            if (arr[i] >= a){
                arr[i] = a;
                flag = 0;
                break;
            }
        }
        if (flag) arr[cnt ++ ] = a;

        i ++ ;
    }

    cout << msf << '\n' << cnt << '\n';

    return 0;
}