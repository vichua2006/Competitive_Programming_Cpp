#include <iostream>
#include <string>
using namespace std;

int l1[26],l2[26];

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    string s1,s2; cin >> s1 >> s2;
    char ans = 'A';
    for (char c:s1){
        if (c != '*') l1[int(c)-int('a')] += 1;
    }
    for (char c:s2){
        if (c != '*') l2[int(c)-int('a')] += 1;
    }
    for (int i=0;i<26;i++){
        if (l2[i] > l1[i]){
            ans = 'N';
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}