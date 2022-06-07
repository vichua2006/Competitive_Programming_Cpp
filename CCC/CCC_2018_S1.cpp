//use that ai-aj will not give better results than ai-aj-1
//only consective intervals should be used in calculation, as anything else will only lower that speed

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ud double

pair<ud,ud> arr[1000000];
int n,t,p;
ud s = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> t >> p;
        arr[i] = {t,p};
    }
    sort(arr,arr+n);
    for (int i=1;i<n;i++){
        s = max(s,abs(arr[i].second-arr[i-1].second)/abs(arr[i].first-arr[i-1].first));
    }
    cout << s << '\n';
    return 0;
}