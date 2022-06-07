/*

swaps = Nc + max(S(a,b),S(b,a))

intuitive understanding:
first swap all the non-C characters in the C section back to their section
with C section all done, we only require (# of a in b) more swaps, which equals max(S(a,b),S(b,a))
think a bit more. The swapping in the c section would not cause max(S(a,b),S(b,a)) to change
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N;
string str;

int solve(char a,char b,char c){
    // 1-p1: 1
    // p1+1-p1+p2: 2
    // p1+p2+1-p1+p2+p3: 3
    // swaps = Nc + max(S(a,b),S(b,a))
    int p1 = 0,p2 = 0,p3 = 0;
    for (char ch:str) p1 += (ch==a),p2 += (ch==b),p3 += (ch==c);
    int Nc = 0,Sab = 0,Sba = 0;
    for (int i=0;i<=p1-1;i++) Sab += (str[i]==b);
    for (int i=p1;i<=p1+p2-1;i++) Sba += (str[i]==a);
    for (int i=p1+p2;i<N;i++) Nc += (str[i]!=c);
    int cnt = INF;
    for (int i=0;i<N;i++){
        cnt = min(cnt,Nc+max(Sab,Sba));
        Sab -= (str[i]==b),Sab += (str[(p1-1+i+1)%N]==b);
        Sba -= (str[(p1+i)%N]==a),Sba += (str[(p1+p2-1+i+1)%N]==a);
        Nc -= (str[(p1+p2+i)%N]!=c),Nc += (str[(N-1+i+1)%N]!=c);
    }
    return cnt;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> str;
    N = str.size();
    // got to account for all the possible orientation
    cout << min(solve('A','B','C'),solve('A','C','B')) << '\n';
    return 0;
}