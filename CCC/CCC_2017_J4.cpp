#include <iostream>
#include <vector>
using namespace std;

void set_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    set_IO();

    int n; cin >> n;
    vector<int> ftime;
    ftime.push_back(34); //12:34
    for (int i=60;i<601;i++){
        int a = (int) i/60;
        int b = (int) (i%60)/10;
        int c = (i%60)%10;
        if (a+c == 2*b){
            ftime.push_back(i);
        }
    }
    ftime.push_back(671); //11:11

    int count = 0;
    count += ((int) n/720)*ftime.size();
    for (int i=0;i<ftime.size();i++){
        if (ftime[i] > n%720){
            break;
        }
        count += 1;
    }
    cout << count << '\n';

}