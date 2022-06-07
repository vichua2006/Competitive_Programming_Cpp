//count letters and determine parity
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1, INF = 1e9, MOD = 1e9 + 7;
int arr[26];
char odd_ch = ' ';
string str,ans;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> str;
    for (char ch: str) arr[int(ch-'A')] += 1;
    for (int i=0;i<26;i++){
        // we can only have one odd number of letters
        if ((arr[i]&1)&&odd_ch != ' ') cout << "NO SOLUTION\n";
        // mark the odd char, subtract one
        if (arr[i]&1) odd_ch = char(i+'A'), arr[i] -= 1;
    }
    for (int i=0;i<26;i++){
        if (arr[i] > 0){
            for (int j=0;j<arr[i]/2;j++) ans.push_back(char(i+'A'));
        }
    }
    // odd length => one letter in middle
    if (str.size()&1){
        cout << ans << odd_ch;
        reverse(ans.begin(),ans.end());
        cout << ans;
    }
    else{
        // if it gets here it means that there are no char that appeared  odd number of times
        cout << ans;
        reverse(ans.begin(),ans.end());
        cout << ans;
    }
    return 0;
}