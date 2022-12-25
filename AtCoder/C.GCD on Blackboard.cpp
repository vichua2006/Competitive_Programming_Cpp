/*
(a, b) denotes the gcd of a and b

suppose we are changing the number ax

realize that (a1, a2, ... , ax, a(x+1), ... , an) = (ax, (a1, a2, ..., a(x-1), a(x+1), ... , an))
thus, (a1, a2, ... , ax, a(x+1), ... , an) <= min(ax, (a1, a2, ..., a(x-1), a(x+1), ... , an))

since we ax is variable, (a1, a2, ... , ax, a(x+1), ... , an) can at most equal (a1, a2, ..., a(x-1), a(x+1), ... , an)

intuitively, it also makes sense; gcd cannot be increased by adding numbers, it's restrictive; each new number is a restriction to the total value

thus, we find (a1, a2, ..., a(x-1), a(x+1), ... , an) for all x by using prefix + suffix sum to compute it
since (a, b, c) = ((a, b), c), 
then  (a1, a2, ..., a(x-1), a(x+1), ... , an) = ((a1, a2, ..., a(x-1)), (a(x+1), ... , an))

to process the prefix-gcd array, we again use the property that (a, b, c) = ((a, b), c)

pre[i] = gcd(pre[i - 1], arr[i])

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int N;
int arr[maxN], pre[maxN], post[maxN];

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=1;i<N+1;i++) cin >> arr[i];
    for (int i=1;i<N+1;i++){
        pre[i] = gcd(arr[i], pre[i - 1]);
        int j = N - i + 1;
        post[j] = gcd(arr[j], post[j + 1]);
    }

    int msf = 0;
    for (int i=1;i<N+1;i++)
        msf = max(msf, gcd(pre[i - 1], post[i + 1]));

    cout << msf << '\n';

    // for (int i=0;i<N+1;i++) cout << pre[i] << ' ';
    // cout << '\n';
    // for (int i=0;i<N+1;i++) cout << post[i] << ' ';

    return 0;
}