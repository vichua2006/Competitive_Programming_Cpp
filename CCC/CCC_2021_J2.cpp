#include <iostream>
#include <string>
using namespace std;

int bid_values[100];
string names[100];

int main(){
    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        int bid;
        string name;
        cin >> name;
        cin >> bid;
        bid_values[i] = bid;
        names[i] = name;
    }

    int max_bid = 0;
    for (int i=0;i<n;i++){
        if (bid_values[i] > max_bid){
            max_bid = bid_values[i];
        }
    }
    int final_idx = 0;
    for (int i=0;i<n;i++){
        if (bid_values[i] == max_bid){
            final_idx = i;
            break;
        }
    }
    cout << names[final_idx] << '\n';
}