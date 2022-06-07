// seems like a simple problem
// each time, first check if the first ingredient in the branch can be pushed into the lake
// if not, then check if the first in the Mt. can be pushed into the lake,
// if not, push ingredient into the branch
// at some point if the configuration is not vaild, Mt would be empty and branch cannot push more ign into lake, at that point,
// break and print N

#include<bits/stdc++.h>
using namespace std;

#define ll long long long
#define ar array

int t,n;
vector<int> s1,s2,s3;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;
    for (int tt=0;tt<t;tt++){
        s1.clear(),s2.clear(),s3.clear();
        cin >> n;
        for (int i=0;i<n;i++){
            int a; cin >> a;
            s1.push_back(a);
        }
        // for each ingredient
        char ans = 'Y';
        while (s1.size()>0 || s2.size()>0){
            int ing;
            if (s2.size()>0){
                ing = s2.back();
                if (ing == s3.size()+1){
                    s2.pop_back();
                    s3.push_back(ing);
                    continue;
                }
            }
            if(s1.size()>0){
                ing = s1.back();
                if (ing == s3.size()+1){
                    s1.pop_back();
                    s3.push_back(ing);
                    continue;
                }
                else{
                    s1.pop_back();
                    s2.push_back(ing);
                    continue;
                }
            }
            
            ans = 'N';
            break;
        }
        cout << ans << '\n';
    }
    return 0;
}