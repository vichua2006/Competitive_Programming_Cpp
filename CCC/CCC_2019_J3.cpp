#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++){
        string str; cin >> str;
        char prechar = str[0];
        int char_count = 0;

        for (int j=0;j< (int) str.length();j++){
            char currchar = str[j];
        
            if (currchar != prechar){
                cout << char_count << ' ' << prechar << ' ';
                char_count = 0;
            }

            prechar = currchar;
            char_count++;

            if (j == (int) str.length()-1){
                cout << char_count << ' ' << prechar << ' ';
            }

            
        }
        cout << '\n';
    }
    return 0;
}