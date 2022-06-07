//seems as if scanf can only read the few built-in types
#include <iostream>
#include <cstdio>
using namespace std;

const int max_lenght = 1000000;

int main(){
    char operations[max_lenght];cin >> operations;
    int h = 0,v = 0;
    for (int i=0;i<max_lenght;i++){
        if (operations[i] == 'H'){
            h ^= 1;
        }
        else if (operations[i] == 'V'){
            v ^= 1;
        }
    }

    int a,b,c,d;
    if (h && v){
        a = 4,b = 3,c = 2,d = 1;
    }
    else if (h){
        a = 3,b = 4,c = 1,d = 2;
    }
    else if (v){
        a = 2,b = 1,c = 4,d = 3;
    }
    else{
        a = 1,b = 2,c = 3,d = 4;
    }

    cout << a << ' ' << b << '\n' << c << ' ' << d;
}




