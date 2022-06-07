#include <iostream>
#include <cstdio>
#include <array>
using namespace std;

int find_sum(int start,int end,int arr[]){
    int sum = 0;
    for (int i=start;i<end;i++){
        sum += arr[i];
    }

    return sum;
}
int main(){
    int arr[5][5];
    int distance[4];
    for (int i=0;i<4;i++){
        scanf("%d",&distance[i]);
    }

    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            if (i == j){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = find_sum(min(i,j),max(i,j),distance);
            }
        }
    }

    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;

}

