//we cannot just blindly increase ai each time as that may lead to more time to reach ai+1,ai+2...etc
//as they now require a larger value because ai is now greater than the optimal bi
//https://codeforces.com/blog/entry/75913
//Lesson learned: how to generate non-decreasing sequence correctly and not f-up greedy solutions

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define maxN 100000

int a[maxN],b[maxN];


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t,n; cin >> t;
    for (int ti=0;ti<t;ti++){
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        b[0] = a[0];
        for (int i=1;i<n;i++){
            b[i] = max(a[i],b[i-1]);//the optimal value of ai (minimum bi-ai such that bi is non decreasing)

        }

        int maxT = 0;
        for (int i=0;i<n;i++){
            // counts the "0"s before the number - the time T needed to achieve that optimal bi
            if (a[i] != b[i]) maxT = max(maxT,32-__builtin_clz(b[i]-a[i]));   
        }
        cout << maxT << '\n';
    }
    return 0;
}