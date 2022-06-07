//greedy, always dock at the highest/largest port possible

#include <iostream>
#include <unordered_map>
using namespace std;

int port[100000];

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,p,g; cin >> n >> p;
    unordered_map<int,int> next_port;
    for (int i=0;i<n;i++) next_port[i] = i;
    for (int i=0;i<p;i++){
        bool landed = false;
        cin >> g;
        for (int j=next_port[g-1];j>-1;j--){
            if (!port[j]){
                port[j] ^= 1;
                landed = true;
                next_port[g-1] = j-1;
                break;
            }
        }
        if (!landed){
            cout << i << '\n';
            return 0;
        }
    }

    cout << p << '\n';
    return 0;
}