//prefix sum (kinda?) calculate the max games won by 
//bessie if she switches gesture at position i for all 1 <= i <= n

#include <iostream>
using namespace std;

int H[100001],P[100001],S[100001];

void setIO(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
}

int max3(int a, int b, int c){
    return max( (int) max(a,b), (int) max(b,c));
}

int main(){
    setIO();
    int n,max_games = 0; cin >> n;
    //           -prefix sum arrays
    for (int i=1;i<n+1;i++){
        char g;cin >> g;
        H[i] = H[i-1] + int(g == 'H');
        P[i] = P[i-1] + int(g == 'P');
        S[i] = S[i-1] + int(g == 'S');
    }
    for (int i=0;i<n+1;i++){
        max_games = max(max_games,max3(H[i],P[i],S[i])+max3(H[n]-H[i],P[n]-P[i],S[n]-S[i]));
    }
    cout << max_games << '\n';

    return 0;
}