#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 3e5 + 10;
int N;
int A[maxN], B[maxN], AA[maxN];
vector<ar<int, 3>> ans;

int find(int c, int x){
    for (int i=c+1;i<N;i++){
        if (AA[i] == x) return i;
    }

    return -1;
}


bool solve(){
    ans.clear();
    memcpy(AA, A, sizeof(A));

    for (int i=0;i<N;i++){
        if (AA[i] != B[i]){
            if (i > 0 && AA[i - 1] == B[i]){
                AA[i] = B[i];
                ans.push_back({0, i - 1, i});
            } else {
                int pos = find(i, B[i]);
                if (pos == -1) return false;
                ans.push_back({1, i, pos});
                for (int j=i;j<=pos;j++) AA[j] = B[i];
            }
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<N;i++) cin >> B[i];


    if (solve()){
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (auto a : ans){
            cout << (a[0] ? "L " : "R ") << a[1] << ' ' << a[2] << '\n';
        }
    } else {
        reverse(A, A + N);
        reverse(B, B + N);

        if (solve()){
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (auto a : ans){
                cout << (a[0] ? "R " : "L ") << N - a[2] - 1 << ' ' << N - a[1] - 1 << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;

}