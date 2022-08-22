// be careful of negative numbers and setting that as range
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5, INF = 1e9;

double N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    // don't use a = -N, b = N, as N could be negative
    double r = 0, c = 0, a = -INF, b = INF;

    while (abs(c-N)>1e-8){
        r = (a+b)/2;
        c = r*r*r;
        if (c > N) b = r;
        else a = r;
    }
    cout.precision(6);
    cout << fixed << r << '\n';
    return 0;
}