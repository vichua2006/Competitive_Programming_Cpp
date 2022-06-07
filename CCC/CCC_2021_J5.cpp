#include <iostream>
#include <numeric>
using namespace std;

void setIO(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    setIO();
    int m,n,k; cin >> m >> n >> k;
    int row[m] = {},col[n] = {};
    for (int i=0;i<k;i++){
        char t; cin >> t;
        int x; cin >> x;
        if (t == 'C') col[x-1] ^= 1;
        else row[x-1] ^= 1;
    }
    int c = 0; c = accumulate(col,col+n,c);
    int r = 0; r = accumulate(row,row+m,r);

    cout << r*n + c*m - 2*r*c << '\n';
}