//proper way, using two pointers
// logic is that, if a+b > x, move b down, because even for the current
// a, b is too big.
// if a+b < x, move a up, because for the currnt b, a is too
// small
// if a+b = x, we have found the two solutions
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 2e5 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,X,arr1[maxN],arr2[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> X;
    for (int i=0;i<N;i++){
        int a; cin >> a;
        arr1[i] = a;
        arr2[i] = a;
    }
    sort(arr2,arr2+N);
    int a = 0, b = N-1;
    while(a<b){
        if (arr2[a]+arr2[b] == X){
            // iterate through the original array again
            int ans1,ans2;
            for (int i=0;i<N;i++){
                if (arr1[i]==arr2[a]){
                    ans1 = i;
                    break;
                }
            }
            for (int i=0;i<N;i++){
                if (arr1[i]==arr2[b]&&i!=ans1){
                    ans2 = i;
                    break;
                }
            }
            cout << ans1+1 <<' '<< ans2+1 << '\n';
            return 0;
        }
        if (arr2[a]+arr2[b] > X) b -= 1;
        else a +=1 ;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}