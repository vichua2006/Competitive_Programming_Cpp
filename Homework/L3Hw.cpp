#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int q1(){
    int a, b;
    cin >> a >> b;
    cout << a << '\n' << b;
    return 0;

    /*
    a) 1
       2
    b) (no output, still waiting for second input)
    c) 12
       0
    */
}

int q2(){
    char a[5];
    cin >> a;
    cout << a;
    return 0;

    /*
    a) 1 (ended upon ' ')
    b) 12
    c) 12_2
    */
}
int q3(){
    string a;
    cin >> a;
    cout << a;
    return 0;

    /*
    a) 1 (cin ends upon whitspace)
    b) 12
    c) 12_2*/
}

int q4(){
    char a[5];
    cin.getline(a ,5);
    cout << a;
    return 0;

    /*
    a) 1 2 (reads x-1 characters)
    b) 12 1
    c) 12_1
    */
}

int q5(){
    float a, b;
    cin >> a >> b;
    cout << a << '\n' << b;
    return 0;

    /*
    a)3.1
      4.14
    b)3.14
      0.14 (????)
    */
}

int q6(){
    int i = 0;
    while (i < 10){
        cout << i << '\n';
        i += 1;
    }
    return 0;
}

int q7(){

    double maxval = -(pow(2,31)),minval = pow(2,31)-1,sum = 0;
    for (int i=0;i<20;i++){
        double n; cin >> n;
        sum += n;
        maxval = max(maxval,n);
        minval = min(minval,n);
    }

    cout << sum/20 << '\n' << maxval << '\n' << minval;
    return 0;
}

int q8(){
    double maxval = -(pow(2,31)),minval = pow(2,31)-1,sum = 0;
    int count = 0;
    while (true){
        double n; cin >> n;
        if (n < 0){
            break;
        }
        sum += n;
        maxval = max(maxval,n);
        minval = min(minval,n);
        count += 1;
    }
    cout << sum/count << '\n' << maxval << '\n' << minval;

    return 0;
}

void q9(){
    char ch;
    cin >> ch;
    switch (ch) {
        case 'a':
            cout << "*" << endl;
            break;
        case 'A':
            cout << "**" << endl;
            break;
        case 'B':
        case 'b':
            cout << "***" << endl;
        case 'C':
        case 'c':
            cout << "****" << endl;
        break;
        default:
            cout << "*****" << endl;
    }
    /*
    a) *
    b) **
    c) ***
       ****
    d) ***
       ****
    e) ****
    f) ****
    g) *****
    */
}

void q10(){
    int value;
    char ch;
    cin >> ch;
    if (ch == 'A') value = 10;
    else if (ch == 'P') cin >> value;
    else if (ch == 'T') value = ch;
    else if (ch == 'V') value = ch + 1000;
    else value = 50;
    cout << value << endl;
}
int main(){
    q10();
    
    return 0;
}
