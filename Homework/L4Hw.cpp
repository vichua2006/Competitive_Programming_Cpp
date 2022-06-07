#include <iostream>
#include <vector>
#include <string>
using namespace std;

int q1(){
    vector<string> cows;
    string line;
    while(getline(cin,line)){
        string str = "";
        for (auto c : line){
            if (c == ' '){
                cows.push_back(str);
                str.clear();
                continue;
            }
            str += c;
        }
        cows.push_back(str);
    }
    for (auto i = cows.begin();i<cows.end();i++) cout << *i << '\n';
    return 0;
}

int q2(){
    string s1,s2; cin >> s1 >> s2;
    if (s1 == s2) cout << "equal" << '\n';
    else cout << max(s1,s2) << " is greater" << '\n';
    return 0;
}

int q2part2(){
    string s1,s2; cin >> s1 >> s2;
    int ss1 = int(s1.size()), ss2 = int(s2.size());
    if (ss1 == ss2) {
        cout << "equal" << '\n';
    }
    else if (ss1 > ss2) {
        cout << s1 << " is longer" << '\n';
    }
    else{
        cout << s2 << " is longer" << '\n';
    }
    return 0;
}

int q3(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    for (auto i = v.begin();i<v.end();i++){
        *i = 2*(*i);
    }
    for (auto i = v.begin();i<v.end();i++){
        cout << *i << ' ';
    }

    return 0;
}

int q4(){
    /*
    because without adding beg, mid would be relative to the literal begining of the vector
    with beg:
    -------------------------beg--------mid--------end
    without beg:
    --------mid--------------beg-------------------end
    */
}

int main(){
    q3();

    return 0;
}