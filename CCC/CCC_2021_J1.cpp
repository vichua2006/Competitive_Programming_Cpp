// haha my first problem in c++, June 20 2021, 21:05

#include <iostream>
using namespace std;

int main(){
    int b = 0;
    cin >> b;

    int p = b*5 - 400;

    if (p == 100){
        cout << p << '\n' << 0;
    }
    else if (p > 100){
        cout << p << '\n' << -1;
    }
    else{
        cout << p << '\n' << 1;
    }

    return 0;

}