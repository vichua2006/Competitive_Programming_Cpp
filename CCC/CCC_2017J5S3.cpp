/*"This means we can iterate over every (unordered) pair of lengths of pieces of wood available 
and add it to the corresponding total for a length of board made. 
Since each length of wood can be uniquely paired up with another length of wood to create a corresponding length of board, 
no pairs are over-counted this way. 
Finally, we can iterate over every possible board length
to determine the length of the longest fence and the heights of all fences which have that length."
https://dmoj.ca/problem/ccc17s3/editorial
(wow, very claer editorial)
*/

#include <iostream>
using namespace std;

int wood[2001];
int board[4001];

void set_IO(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    set_IO();
    int n; cin >> n;
    for (int i=0;i<n;i++){
        int w; cin >> w;
        wood[w] += 1;
    }
    for (int i=1;i<2001;i++){
        for (int j=i;j<2001;j++){
            if (i == j){
                board[i+j] += wood[i] >> 1; // bitwise operator, shifts all bits to the right by one (equivalent of x/2)
            }
            else{
                board[i+j] += min(wood[i],wood[j]);
            }
        }
    }
    int count = 0, max_length = 0;
    for (int i=0;i<4001;i++){
        if (board[i] > max_length){
            max_length = board[i];
            count = 1;
        }
        else if (board[i] == max_length) count += 1;
    }

    cout << max_length << ' ' << count << '\n';

}