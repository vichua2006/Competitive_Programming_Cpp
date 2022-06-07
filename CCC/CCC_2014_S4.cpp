/*

basically double sliding window

we set the horizonatal beginning and end of all rectangles as events
thus, the vertical strip between any two events should be uniformly tinted like so:
.....
.....
.....
#####
#####
@@@@@
@@@@@
@@@@@
@@@@@
.....
.....

and so we avoid situations like:
...%%
...%%
...%%
###%%
###%%
@@@@@
@@@@@
@@***
@@***
..***
..***

(an example of strip with length 5. . , # , @ , % , represents different tinted values)
then we can sweep horizontally over the rectangles, and for every strip in between two events, vertically sweep through it and compute any area with tint value >= T
implementation is annoying to describe, so I am not going to explain it.

However, this RTEs three cases. Why?
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const ll maxN = 3e3+1,INF = 1e9,maxK = 1e9;
ll N,T;
// x, start y, end y, tint value, type (start=1 or end=0)
vector<ar<ll,5>> arr;
// y, tint value, type
multiset<ar<ll,3>> slide;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> T;
    // place dummy variables to avoid extra conditional statements later
    arr.push_back({0,0,maxK,0,1}), arr.push_back({maxK,0,maxK,0,0});
    for (int i=0;i<N;i++){
        ll a,b,c,d,k; cin >> a >> b >> c >> d >> k;
        arr.push_back({a,b,d,k,1}), arr.push_back({c,b,d,k,0});
    }
    sort(arr.begin(),arr.end());
    slide.insert({0,0,1}),slide.insert({maxK,0,0});

    ll area = 0;
    for (int i=1;i<arr.size();i++){
        ar<ll,5> evt = arr[i];
        ll currx = evt[0],sy = evt[1],ey = evt[2],kx = evt[3],tx = evt[4];
        ll prex = arr[i-1][0];
        ll curr_tint = 0;
        auto it = slide.begin();
        // skips the dummy variable, slide throught the current x section;
        it++;
        ll prey = 0;
        for (it;it!=slide.end();it++){
            ar<ll,3> a = *it;
            ll curry = a[0],ky = a[1],ty = a[2];
            if (curr_tint>=T){
                area += (curry-prey)*(currx-prex);
                // cout << area << '\n';
            }
            if (ty) curr_tint += ky;
            else curr_tint -= ky;
            prey = curry;
        }
        // update next section
        if (tx){
            slide.insert({sy,kx,1}),slide.insert({ey,kx,0});
        } else {
            // auto r1 = slide.find({sy,kx,1}), r2 = slide.find({ey,kx,0});
            // if (r1!=slide.end())
            slide.erase(slide.find({sy,kx,1}));
            // if (r2!=slide.end())
            slide.erase(slide.find({ey,kx,0}));
        }
    }
    cout << area << '\n';
    return 0;
}