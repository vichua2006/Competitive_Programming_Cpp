#include <iostream>
#include <array>
#include <cmath>
using namespace std;
int X[5000];
int Y[5000];

int main(){
    int n = 0,x = 0,y = 0;

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        X[i] = x;
    }
    for (int i=0;i<n;i++){
        cin >> y;
        Y[i] = y;
    }

    int euclidean_distance = 0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int newdis = pow(X[i]-X[j],2) + pow(Y[i]-Y[j],2);
            if (euclidean_distance < newdis){
                euclidean_distance = newdis;
            }
        }
    }

    cout << euclidean_distance << '\n';

    return 0;
}