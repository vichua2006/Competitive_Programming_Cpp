//unordered map can't store coordinates so using array instead
#include <iostream>
using namespace std;

int grass[2001][2001] = {};

void set_IO(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);
}

int main(){
    set_IO();
    int n,x = 1000,y = 1000, regrowth_time = 2147483647,time = 1;
    // s <= 10, n <= 100 therefore total distance <= 10*100 = 100
    // also, 0 to indicate unvisited grass
    cin >> n;
    grass[x][y] = 1;
    // start on (1000,1000)
    for (int i=0;i<n;i++){
        char direction;
        int distance;
        cin >> direction >> distance;
        for (int j=0;j<distance;j++){
            if (direction == 'N') y++;
            if (direction == 'S') y--;
            if (direction == 'E') x++;
            if (direction == 'W') x--;
            // update regrowth_time
            time += 1;
            if (grass[x][y] != 0){
                regrowth_time = min(regrowth_time,time-grass[x][y]);
            }
            grass[x][y] = time;
        }
    }
    if (regrowth_time == 2147483647) regrowth_time = -1;
    cout << regrowth_time << '\n';


    return 0;
}