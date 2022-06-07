//is there a way to prun the search so that it passes on dmoj?

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

pair<string,string> r[3];
vector<pair<int,pair<int,string>>> rec;
unordered_set<string> v[16];
int S;
string I,F;

string apply_rule(int idx, string s1,string s2,string p){
    string pp = p.substr(0,idx);
    pp.append(s2);
    pp.append(p.substr(idx+s1.size()));
    return pp;
}

bool solve(int cstep = 0,string cstr = ""){
    if (cstep == S && cstr == F) return true;
    if (cstep == S) return false;
    if (v[cstep].find(cstr) != v[cstep].end()) return false;

    v[cstep].insert(cstr);

    for (int i=0;i<cstr.size();i++){
        for (int rr=0;rr<3;rr++){
            if (cstr[i] == r[rr].first[0]){
                if (cstr.substr(i,r[rr].first.size()) == r[rr].first){
                    string ncstr = apply_rule(i,r[rr].first,r[rr].second,cstr);
                    rec.push_back({rr+1,{i+1,ncstr}});
                    if (solve(cstep+1,ncstr)){
                        return true;
                    }
                    rec.pop_back();
                }
            }
        }
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i=0;i<3;i++) cin >> r[i].first >> r[i].second;
    cin >> S >> I >> F;
    solve(0,I);
    for (int i=0;i<rec.size();i++){
        cout << rec[i].first << ' ' << rec[i].second.first << ' ' << rec[i].second.second << '\n';
    }
    return 0;
}