/*



*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
int T, N;
// since all elements are in the range [1, 1e9], -1 and 1e9 + 1 are suitable
int dx[2] = {-1, INF + 1};
int ori[maxN], arr[maxN];

void fill(){
    // fills the array 
    for (int i=2;i<N-1;i++){
        if (!arr[i]){
            if (arr[i - 1] == -1 || arr[i - 2] > arr[i - 1]) arr[i] = INF + 1;
            else arr[i] = -1;
        }
    }
}

bool check(){
    // checks if the current array is valid
    for (int i=1;i<N-1;i++){
        if (!((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]))) return false;
    }

    return true;
}

void testcase(){
    cin >> N;
    for (int i=0;i<N;i++) cin >> ori[i];
    // brute force all possible first, second, and last elements
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                for (int i=0;i<N;i++) arr[i] = ori[i];
                if (!arr[0]) arr[0] = dx[i];
                if (!arr[1]) arr[1] = dx[j];
                if (!arr[N - 1]) arr[N - 1] = dx[k];

                fill();
                if (check()){
                    cout << "YES\n";
                    return ;
                }
            }
        }
    }

    cout << "NO\n";
    return ;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> T;
    while (T -- ) testcase();

    return 0;
}