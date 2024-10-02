/*



*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
ll N = 1e4;
ll dp[maxN];

void setIO(string name = "")
{
    freopen((name + ".txt").c_str(), "w", stdout);
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    setIO("out");

    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i - 1 == 2 * j)
                dp[i] += dp[j] * dp[j];
            else
                dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    for (int i = 0; i < N; i++)
        cout << dp[i] << '\n';
    return 0;
}