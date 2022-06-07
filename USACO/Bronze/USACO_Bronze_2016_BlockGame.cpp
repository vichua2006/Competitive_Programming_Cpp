#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void setIO(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);
}

int main(){
    setIO();
    int letters[26] = {};
    unordered_map<char,int> lcount1,lcount2;
    int n; cin >> n;
    for (int i = 0;i<n;i++){
        string w1,w2;cin >> w1 >> w2;
        lcount1.clear();lcount2.clear();
        for (char c : w1) lcount1[c] += 1;
        for (char c : w2) lcount2[c] += 1;
        for (int j=0;j<26;j++) letters[j] += max(lcount1[char(int('a')+j)],lcount2[char(int('a')+j)]);
    }
    for (int i=0;i<26;i++){
        cout << letters[i] << '\n';
    }

    return 0;
}