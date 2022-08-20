/*

if we simply brute force it with 2-d prefix sum array, it still TLEs with a complexity of O(N^4)

an opimization can be made with two pointers:


        i        j

        |        |
        |        |
        |        |
 k --------------------------
        |        |
        |        |
        |        |
        |        |
 l --------------------------
        |        |
        |        |
        |        |

where pointer i, j are used to iterate all possible widths of the subarray 
the fast pointer l maintains the bottom edge of the subarray, and passive/slow k maintains the 
**potential** top of the subarray

they both start at the top of the subarray and move downwards. Each time l moves down, and the total sum does not exceed K, 
every subarray with width j - i + 1 and bottom l, and height of 1 ~ l - k + 1 (every array in the boxes area with l as the bottom)
is a valid subarray (because the value of aij is positive). pointer k moves in the event that the total sum exceeds K, and stops when it no longer does.

Because l is never the same, no valid subarray is a counted twice. Suppose k remains stationary, and the entire subarray still valid, 
by l iterating from k to its current position, all subarrays in [k, l] are counted


TLEd, turns out that the limit is quite tight, and even just defining an extra set_IO() was enough for TLE
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 5e2 + 10;
ll N, M, K;
ll pre[maxN][maxN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M >> K;
    // compute prefix sum
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            cin >> pre[i][j];
            pre[i][j] += pre[i][j - 1] + pre[i - 1][j]  - pre[i - 1][j - 1];
        }
    }
    // iterate width
    ll cnt = 0;
    for (int i=1;i<M+1;i++){
        for (int j=i;j<M+1;j++){
            // corners are: (k, i) and (l, j)
            for (int k=1, l=1;l<N+1;l++){
                // while the sum of the subarray is greater than K  
                while (pre[l][j] - pre[l][i - 1] - pre[k - 1][j] + pre[k - 1][i - 1] > K && k <= l) k ++ ;
                // in the case where k > l, just continue, because it means that just the row l along
                // sums to a number greater than K, and thus no valid subarray could contain such a row.
                if (k <= l) cnt += l - k + 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}