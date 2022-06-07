/*
first, calculate all possible initial values
then, test each initial value by calculating the rest of the scoring
all elements of b should be in the socring for it to be a vaild solution
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int a[2000], b[2000], sum[2000];

void setIO(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    setIO();
    int k,n,ans = 0; cin >> k >> n;
    unordered_set<int> all_init_scores;
    for (int i=0;i<k;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    //                  -calculate a array sum where sum[i] is the sum of 0-ith jury mark
    sum[0] = a[0];
    for (int i=1;i<k;i++) sum[i] = a[i] + sum[i-1];
    //                  -find all possible initial scores
    for (int i=0;i<k;i++){
        // why does it only have to be b[0] and not b[0],b[1]...b[n]?
        // ah, because b[0] must be a final part of the score
        // therefore all init scores must AT LEAST satisfy b[0] being in some position i
        // for it to even be a potential init score (if it doesn't even satisfy this constrain,
        // that means that b[0] is NOT included in that scoring, making it invalid)
        // from this perspective, then all b[i] can be used and it would produce the same
        // or just more init scores. b[0] is used because it is guarenteed to exist
        int init_score = b[0]-sum[i];
        all_init_scores.insert(init_score);
    }
    //                  -test all initial scores
    for (auto v : all_init_scores){
        int add_to_ans = 1;
        unordered_set<int> scoring;
        //              -exclude initial score, as it is not included in b1,b2....bn
        for (int i=0;i<k;i++){
            scoring.insert(v + sum[i]);
        }
        for (int i=0;i<n;i++){
            if (scoring.find(b[i]) == scoring.end()){
                add_to_ans = 0;
                break;
            }
        }
        ans += add_to_ans;
    }
    cout << ans << '\n';

    return 0;
}