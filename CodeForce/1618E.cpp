// this is basically a math problem?
// we know that bi = ai + 2*a(i-1) + 3*a(i-2) ... + i*a(1, which equals i-(i-1)).. + n*a(i+1)
// therefore, b1 + b2 ... + bn = (1+2+...+n)(a1+a1+...+an) = (n+1)*n/2 * (a1+...an)
// => sum(bi)*2/(n+1)*n = sum(ai)
// therefore, if sum(bi)%((n+1)*n/2) != 0, then it is impossible
// let Sa = sum(a)
// bi - b(i-1) = ai + 2a(i-1) +...+na(i+1) - (a(i-1) + 2a(i-2) +...na(i-n mod n = i))
// = ai - nai + 2a(i-1)-a(i-1) +...+ (k+1)a(i-k)-ka(i-k) +...+na(i+1)-(n-1)a(i+1)
// = -nai + ai + a(i-1)+...a(i+1) = -nai + Sa
// therefore ai = (Sa - (bi-b(i-1)))/n = (Sa + b(i-1) - bi)/n;
// if it is not an integer or is negative, it is impossible
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 4e4 + 1, INF = 1e9, MOD = 1e9 + 7;
ll N,B[maxN],A[maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int ii=0;ii<N;ii++){
        ll n,Sb = 0; cin >> n;
        string ans = "YES\n";
        // 1-indexed for sanity
        for (int i=1;i<n+1;i++) cin >> B[i], Sb += B[i];
        // if the sum of ai is not an integer
        if (Sb%(n*(n+1)/2) != 0) ans = "NO\n";
        ll Sa = Sb/(n*(n+1)/2);
        for (int i=1;i<n+1;i++){
            // if ai is not an integer or not positive
            // since it is circular, the city before 1 is city n, so needed to make sure that works
            if ((Sa + B[(i == 1?n:i-1)] - B[i])%n != 0 || 
            (Sa + B[(i == 1?n:i-1)] - B[i])/n <= 0){
                ans = "NO\n";
            }
            A[i] = (Sa + B[(i == 1?n:i-1)] - B[i])/n;
        }
        cout << ans;
        if (ans == "YES\n"){
            for (int i=1;i<n+1;i++) cout << A[i] << (i == n?'\n':' ');
        }
    }
    return 0;
}