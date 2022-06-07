//another classic
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 5e3 + 1, INF = 1e9, MOD = 1e9 + 7;
int N,M,dp[maxN][maxN];
char s1[maxN],s2[maxN];
string ss1,ss2;

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> ss1 >> ss2;
    N = ss1.size(),M = ss2.size();
    for (int i=0;i<N;i++) s1[i+1] = ss1[i];
    for (int i=0;i<M;i++) s2[i+1] = ss2[i];
    // dp[i][j] contains the edit distance the first i characters of the first word
    // to the j characters of the second word
    // initialization of the first rwo and column, since they are more annoying than the other cells
    // in the first row, the ED (haha I have been reading the Magic University arc of Mushoku Tensei
    // and the word ED was getting used quite frequently with a different meaning) is basically the length of the word,
    // but if the first letter of s1 is included in s2, then if would be length -1 as that letter would not need to be changed
    bool f_in_s = false;
    for (int i=1;i<N+1;i++)f_in_s = (s1[i] == s2[1]?f_in_s = 1:f_in_s = f_in_s),dp[i][1] = i - f_in_s;
    f_in_s = false;
    for (int i=1;i<M+1;i++)f_in_s = (s1[1] == s2[i]?f_in_s = 1:f_in_s = f_in_s),dp[1][i] = i - f_in_s;
    for (int i=2;i<N+1;i++){
        for (int j=2;j<M+1;j++){
            // let s(n) the first n letters of s
            // to edit s1(i) to s2(j) we have three options: 
            // transform s1(i) to s2(j-1), then append the last char s2[j]
            // transform s2(j) to s1(i-1), then append the last char s1[i]
            // transform s1(i-1) to s2(j-1), then edit s1[i] to s2[j], however, a bit of a special case,
            // if s1[i] equals s2[j], then there won't need a extra step
            dp[i][j] = min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1] + (s1[i] != s2[j]));
        }
    }
    cout << dp[N][M] << '\n';
    return 0;
}