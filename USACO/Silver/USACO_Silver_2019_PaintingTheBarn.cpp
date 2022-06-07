//another rectangle geometry problem...or so i thought
//wait, how is this prefix sum?

#include <iostream>
using namespace std;

int barn[1001][1001] = {0};

void setIO(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("paintbarn.in","r",stdin);
    // freopen("paintbarn.out","w",stdout);
}

int main(){
    setIO();
    int n,k,ans = 0; cin >> n >> k;
    for (int i=0;i<n;i++){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int x=x1;x<x2;x++){
            for (int y=y1;y<y2;y++){
                barn[x][y] += 1;
                // cout << x << ' ' << y << '\n';
            }
        }
    }
    for (int i=1;i<1001;i++){
        for (int j=1;j<1001;j++){
            if (barn[i][j] == k) ans += 1;
        }
    }

    cout << ans << '\n';
    return 0;
}