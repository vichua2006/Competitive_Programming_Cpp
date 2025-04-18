/*



*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N = 80;
int arr[maxN], num[] = {3, 8, 12};

int f(int a, int b) { return a + b; }

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    // setIO();

    int a, b;
    cin >> a >> b;
    cout << f(a, b) << '\n';
    return 0;
}
