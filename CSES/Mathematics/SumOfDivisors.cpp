/*

refer to lesson 11 of CCC 2022
even though it could be simplified to the form

for each factor i from 1~N
we calculate how many times it appears = (N-i)/i + 1
and sum it

and notice

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e6 + 1,INF = 1e9,MOD = 1e9+7;
ll N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=1;i*i<=N;i++){
        ll ocr = (N-i)/i + 1;
        ll s = ((ocr%MOD)*i)%MOD;
    }
}