//meet in the middle,calculate all n/2 steps and rec results from boths ends and check through the intersection

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

pair<string,string> r[3];
unordered_map<string,vector<pair<int,pair<int,string>>>> all_rec;
vector<pair<int,pair<int,string>>> rec;
unordered_set<string> v[16];
int S;
string I,F,connector = "";

string apply_rule(int idx, string s1,string s2,string p){
    string pp = p.substr(0,idx);
    pp.append(s2);
    pp.append(p.substr(idx+s1.size()));
    return pp;
}

void solve1(int cstep = 0,int Sn = 0,string cstr = ""){
    //used to map out all the possible strings
    if (cstep == Sn){
        all_rec[cstr] = rec;
        return;
    }
    if (v[cstep].find(cstr) != v[cstep].end()) return;

    v[cstep].insert(cstr);

    for (int i=0;i<cstr.size();i++){
        for (int rr=0;rr<3;rr++){
            if (cstr[i] == r[rr].first[0]){
                if (cstr.substr(i,r[rr].first.size()) == r[rr].first){
                    string ncstr = apply_rule(i,r[rr].first,r[rr].second,cstr);
                    rec.push_back({rr+1,{i+1,ncstr}});
                    solve1(cstep+1,Sn,ncstr);
                    rec.pop_back();
                }
            }
        }
    }
}

bool solve2(int cstep = 0,int Sn = 0,string cstr = ""){
    // finds an itersection of the two sets and connect the two halves
    if (cstep == Sn && (all_rec.find(cstr) != all_rec.end())){
        connector = cstr;
        return true;
        }
    if (cstep == Sn) return false;
    if (v[S-cstep].find(cstr) != v[S-cstep].end()) return false;

    v[S-cstep].insert(cstr);

    for (int i=0;i<cstr.size();i++){
        for (int rr=0;rr<3;rr++){
            if (cstr[i] == r[rr].first[0]){
                if (cstr.substr(i,r[rr].first.size()) == r[rr].first){
                    string ncstr = apply_rule(i,r[rr].first,r[rr].second,cstr);
                    rec.push_back({rr+1,{i+1,cstr}});
                    if (solve2(cstep+1,Sn,ncstr)){
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
    int s1 = S/2,s2 = S - s1;
    // maps out n/2 steps
    solve1(0,s1,I);
    // reverse the operations
    for (int i=0;i<3;i++){
        swap(r[i].first,r[i].second);
    }
    //connect the halves
    solve2(0,s2,F);
    // rec should be empty after calling solve1, so this is the sequence from F to connector,reversed
    reverse(rec.begin(),rec.end());

    for (int i=0;i<all_rec[connector].size();i++){
        cout << all_rec[connector][i].first << ' ' << all_rec[connector][i].second.first << ' ' 
        << all_rec[connector][i].second.second << '\n';
    }
    for (int i=0;i<rec.size();i++){
        cout << rec[i].first << ' ' << rec[i].second.first << ' ' << rec[i].second.second << '\n';
    }
    return 0;
}