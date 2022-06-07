//the infamous string hashing problem, uses robin-karp algorithm
//32 bit hash is not enough to prevent collisions, but 64 bit integers will overflow during hashing


// something is wrong with the hash

#include <bits/stdc++.h>
using namespace std;

#define ll long long


string N,H;
unordered_set<ll> s1,s2;
int pN[26],lN[26];
const ll maxN = 200000,A1 = 91,A2 = 43,B1 = 1e9+7,B2 = 1e10+7;
ll h1[maxN],h2[maxN],c = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H;
    //rabin-karp sweeping
    for (int i=0;i<N.size();i++){
        pN[int(N[i]-'a')] += 1;
        lN[int(H[i]-'a')] += 1;
    }
    //calculate the prefix sum of hash values for O(1) hashing
    h1[0] = H[0]; h2[0] = H[0];
    for (int i=1;i<H.size();i++){
        h1[i] = (A1*h1[i-1]+H[i])%B1;
        h2[i] = (A2*h2[i-1]+H[i])%B2;
    }
    ll const1 = ((ll) pow(A1,N.size()))%B1; 
    ll const2 = ((ll) pow(A2,N.size()))%B2;

    for (int i=N.size()-1;i<H.size()+1;i++){
        //compute hash value
        bool vaild = true;
        for (int j=0;j<26;j++){
            if (pN[j] != lN[j]){
                vaild = false;
                break;
            }
        }
        if (vaild){

            ll hv1 = h1[i]-(h1[i-N.size()]*const1)%B1;
            ll hv2 = h2[i]-(h2[i-N.size()]*const2)%B2;
            if ((s1.find(hv1) == s1.end())||(s2.find(hv2) == s2.end())){
                s1.insert(hv1);
                s2.insert(hv2);
                c += 1;
            } 
        }
        // prevent corner case where |H| == |N| and it not scanning the last |N| characters
        if (i == H.size()-1) break;
        lN[int(H[i-N.size()+1]-'a')] -= 1;
        lN[int(H[i+1])-'a'] += 1;
    }
    cout << c << '\n';
    return 0;
}