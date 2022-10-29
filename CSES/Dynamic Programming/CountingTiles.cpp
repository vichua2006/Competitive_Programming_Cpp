/*

for more detailed explaination, refer to the file of the same name in the acwing folder
the expect time complexity was O(n* 2 ^ 2m), and in this case, it would have amounted to 
1e9, which is way past the limit

however, by precomputation, it appears that we were able to reduce the number of operations by at least tenfold

update:
testes the number of operations (roughly) performed when calculating N = 10 and M = 1000, and 
only 6794086 operations, which is almost 1000 times less than the prediction

N = 11, M = 1000 : 18063557
N = 12, M = 1000 : 50257099
N = 13, M = 1000 : 147929240

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 10,maxM = 1 << 15,maxK = 0,INF = 1e9, MOD = 1e9 + 7;
int N, M, op_cnt = 0;
ll dp[maxN][maxM];
bool val[maxM];
vector<int> states[maxM];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N >> M;
    // precompute all valid states
    for (int i=0;i<1<<N;i++){
        int cnt = 0;
        bool flag = 1;
        for (int j=0;j<N;j++){
            if ((i >> j) & 1){
                if (cnt & 1){
                    flag = 0;
                    break;
                }
                cnt = 0;
            } else cnt += 1;

            op_cnt += 1;

        }
        if (cnt & 1) flag = 0;
        val[i] = flag;
    }

    // for each valid state, compute all other states that it is compatible with
    for (int i=0;i<1<<N;i++){
        for (int j=0;j<1<<N;j++){
            // has no overlap and is valid when combined
            if ((i & j) == 0 && val[i | j]) states[i].push_back(j);

            op_cnt += 1;
        }
    }

    dp[0][0] = 1;
    for (int i=1;i<M+1;i++){
        for (int j=0;j<1<<N;j++){
            for (auto k : states[j]) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD, op_cnt += 1;
        }
    }

    cout << dp[M][0] << '\n';

    cout << op_cnt << '\n';

    return 0;
}