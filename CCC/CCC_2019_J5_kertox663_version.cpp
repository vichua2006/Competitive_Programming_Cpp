/*
Link to problem:
https://dmoj.ca/problem/ccc19j5
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>
#include <algorithm>
#include <cmath>
#define ZERO 'A'
#define ONE  'B'

using namespace std;

const unsigned long one = 1;

unsigned long makeBin(string s){
    unsigned long bin = 0;
    for(unsigned i = 0; i < s.length(); i++){
        if(s[i] == ONE) bin += (one << i);
    }
    return bin;
}

struct bin_str{
    unsigned long l, b;
    bin_str(){}
    bin_str(string s){
        l = s.length();
        b = makeBin(s);
    }

    string to_string(){
        string s = "";
        for(unsigned i = 0; i < l; i++){
            if((one<<i)&b){
                s += ONE;
            } else{
                s += ZERO;
            }
        }
        return s;
    }
};

struct pat{
    bin_str from, to;
    int netA, netB;    
};

string from, to;
string start,final;
bin_str startBS, finalBS;
short m, netA, netB;
pat pats[3];
string path = "";

bin_str str; 
array<unsigned long, 3> comb;
int mid = 0;

unordered_set<unsigned long> visited;

vector<int> getIndices(bin_str s, bin_str p){
    vector<int> inds;
    unsigned long f = (one << p.l) - 1;
    for(int i = 0; i + p.l <= s.l; i++){
        unsigned long n = p.b << i;
        unsigned long n2 = f << i;
        unsigned long n3 = s.b & n2;
        if(n3 == n) {
            inds.push_back(i);
        }
    }
    return inds;
}

bin_str splice(bin_str s, pat p, int n){
    unsigned long left = (one << n) - 1;
    unsigned long right = (one << (s.l)) - (one << (n+p.from.l));
    unsigned long result;
    if(p.to.l > p.from.l)
        result = (s.b&left) + (p.to.b << n) + ((s.b&right) << (p.to.l - p.from.l));
    else
        result = (s.b&left) + (p.to.b << n) + ((s.b&right) >> (p.from.l - p.to.l));
    bin_str r;
    r.b = result;
    r.l = s.l + p.to.l - p.from.l;
    return r;
}

bool midSorter(int a, int b){
    return abs(mid-a) <= abs(mid-b);
}

bool search(){
    unsigned long arrInt = (comb[0]<<59) + (comb[1] << 55) + (comb[2] << 51);
    unsigned long c = str.b ^ arrInt;
    if(visited.find(c) != visited.end()){
        return false;
    }
    visited.insert(c);

    if(m == 0){
        return str.b == finalBS.b;
    }

    for(int i = 0; i < 3; i++){
        if(comb[i] > 0){
            vector<int> inds = getIndices(str, pats[i].from);
            mid = str.l/2;
            sort(inds.begin(), inds.end(), midSorter);
            comb[i]--;
            for(int j : inds){
                bin_str next = splice(str, pats[i], j), temp = str;
                str = next;
                m--;
                if(search()){
                    path = path + to_string(i+1) + " " + to_string(j+1) + " " + temp.to_string() + "\n";
                    return true;
                }
                str = temp;
                m++;
            }
            comb[i]++;
        }
    }
    return false;
}


void findPosPath(){
    for(int i = 0; i <= m; i++){
        comb[2] = i;
        for(int j = 0; j <= m-i; j++){
            comb[0] = m-i-j;
            comb[1] = j;
            int sA = 0, sB = 0;
            for(int p = 0; p < 3; p++){
                sA += comb[p]*pats[p].netA;
                sB += comb[p]*pats[p].netB;
            }
            if(sA == netA && sB == netB){
                if( search() ) return;
            }
        }
    }
}

int main(){
    for(int i = 0; i < 3; i++){
        cin >> to >> from;
        int nA, nB;
        nA = count(to.begin(), to.end(), 'A') - count(from.begin(), from.end(), 'A');
        nB = count(to.begin(), to.end(), 'B') - count(from.begin(), from.end(), 'B');
        pats[i] = {bin_str(from), bin_str(to), nA, nB};
    }
    cin >> m >> final >> start;
    startBS = bin_str(start);
    finalBS = bin_str(final);
    str = startBS;
    netA = count(final.begin(), final.end(), 'A') - count(start.begin(), start.end(), 'A');
    netB = count(final.begin(), final.end(), 'B') - count(start.begin(), start.end(), 'B');

    findPosPath();
    cout << path;
    return 0;
}