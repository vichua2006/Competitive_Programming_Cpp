// recursive brute force?
// yes, it is pretty much backtracking
// each dfs scope stores the current position, direction, and the number of turns taken.
// TLE's (8 and 10) probably due to lack of memorization, if dp solution could be implemented (or memorization for the current recursive dfs),
//(4D dp (I think, but isn't that way too hard for bronze?): dp[x][y][direction][number_of_turns] = ways to get here under those constrains)
// it would probably pass.
// aah, it seems as if i just shouldn't have used a return value but instead just a global counter
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 50 + 1, INF = 1e9, MOD = 1e9 + 7;
int T,N,K,ans = 0;
char g[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int x, int y, int k, bool d){
    // d is direction: 0 is right, 1 is down
    if (g[x][y] == 'H'||x > N||y > N||k<0) return;
    // there could be situations where it could no longer turn (k == 0), but still continues down the same direction until it
    // it goes out of bounds; this condition rids of those situations, hence why it is effective (1900ms -> 200 ms)
    if (x != N&&y != N&&k == 0) return;
    if (x == N&& y == N&& k >= 0){ans += 1; return;}
    // interestingly enough, if the line below this was un-commented, my time would go from 200 ms to 1700ms
    // simply due there being three vectors in each function scope; makes sense, it has to allocate space for each call
    // and there could be A LOT of calls to dfs(); lesson learned: recursive dfs should have the absolute minimum variable per call
    // because the amount of stuff is actually busting time limit before it busts memory limit

    // vector<int> node = {1,2,3,4,5,6,7,8},n1 = {1,2},n2 = {1,2};
    // two options: continuing, or change direction
    if (d){
        dfs(x+1,y,k,d),dfs(x,y+1,k-1,d^1);
    }
    else{
        dfs(x,y+1,k,d),dfs(x+1,y,k-1,d^1);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    for (int ii=0;ii<T;ii++){
        cin >> N >> K;
        ans = 0;
        for (int i=1;i<N+1;i++) for (int j=1;j<N+1;j++) cin >> g[i][j];
        dfs(1,2,K,0),dfs(2,1,K,1);
        cout << ans << '\n';
    }
}