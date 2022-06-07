#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void setIO(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("hoofball.in","r",stdin);
    // freopen("hooofball.out","w",stdout);
}

int main(){
    setIO();
    int n; cin >> n;
    vector<int> cows;
    unordered_map<int,int> cow_to_pos;
    cows.reserve(n);
    for (int i=0;i<n;i++){
        int pos; cin >> pos;
        cows.push_back(pos);
        cow_to_pos[pos] = i;
    }
    sort(cows.begin(),cows.end());
    //               -pass the ball to all cows and record the cows that touch the ball
    for (int i=0;i<n;i++){
        
    }

}