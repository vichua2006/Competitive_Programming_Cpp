// the add function has some neatly written conditions and logic

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5, INF = 1e9;


vector<int> add(vector<int> &A, vector<int> &B){
    int t = 0;
    vector<int> C;
    for (int i=0;i<A.size()||i<B.size();i++){
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t%10);
        t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<int> A, B;
    string a, b;

    cin >> a >> b;
    for (int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for (int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');

    vector<int> C = add(A, B);

    reverse(C.begin(), C.end());

    for (int a:C) cout << a;
    return 0;
}