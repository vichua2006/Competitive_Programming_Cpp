#include <iostream>
#include <string>

using namespace std;

int main(){
    string fence,turn;
    int n = 0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> fence;
        int lcount = 0, rcount = 0;
        for (int j=0;j<fence.length()-1;j++){
            turn = fence.substr(j,2);
            if (turn == "NW" || turn == "WS" || turn == "SE" || turn == "EN"){
                lcount = lcount + 1;
            }
            else if (turn == "WN" || turn == "NE" || turn == "ES" || turn == "SW"){
                rcount = rcount + 1;
            }
        
        }
        if (rcount > lcount){
            cout << "CW\n";
        }
        else{
            cout << "CCW\n";
        }
    }
    return 0;
}