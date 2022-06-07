//so, find gcd of all the odd number see if it divids any of the even elements
//if not, find gcd of all even elements and see if it divids any odd element
//if both are false, output 0
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e2 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,arr[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll gcd(ll a,ll b){
    while (a > 0 && b > 0){
        if (a < b) swap(a,b);
        a = a%b;
    }
    return max(a,b);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int ii=0;ii<N;ii++){
        ll n,g_even = 0,g_odd = 0; cin >> n;
        for (int i=0;i<n;i++) cin >> arr[i];
        for (int i=0;i<n;i+=2) g_even = gcd(g_even,arr[i]);
        for (int i=1;i<n;i+=2) g_odd = gcd(g_odd,arr[i]);
        // check for divisibility
        for (int i=0;i<n;i+=2){
            if (arr[i]%g_odd == 0){
                g_odd = 0;
                break;
            }
        }
        for (int i=1;i<n;i+=2){
            if (arr[i]%g_even == 0){
                g_even = 0;
                break;
            }
        }
        cout << max(g_even,g_odd) << '\n';
    }
    return 0;
}