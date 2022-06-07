/*greedy? for max, assume it always happen on -1, for min, assume it never happended on -1*/

#include <iostream>
using namespace std;


void setIO(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
}

int main(){
    setIO();
    int n; cin >> n;
    int log[n] = {},min_breakout = 0,max_breakout = n;
    for (int i=0;i<n;i++){
        int entry; cin >> entry;
        log[i] = entry;
    }
    //              -go backwards as it is difficult to count entries in order
    int no_breakouts_for = 0;
    for (int i=n-1;i>-1;i--){
        //          -no breakouts will happend when this counter > 0
        if (no_breakouts_for > 0){
            no_breakouts_for -= 1;
        }
        //          -if the log specified a date for the previous breaout
        else if (log[i] != -1){
            no_breakouts_for = log[i];
            max_breakout -= log[i];
            min_breakout += 1;
        }
        //          -then log[i] must be -1, in which case we need to test for a corner case
        else if (i == 0){
            min_breakout += 1; // becasue the log always starts on the day of a break out
        }
    }
    
    cout << min_breakout << ' ' << max_breakout << '\n';

    return 0;
}