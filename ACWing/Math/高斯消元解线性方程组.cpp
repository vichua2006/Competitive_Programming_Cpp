/*

to solving the system of equations, we must rearrange the entire thing into a form described below:

a11x1 + a12x +...+ a1nxn = b1
        a22x +...+ a2nxn = b2
              ...
                   annxn = bn

then, we can simply solve our way back up

to complete the rearranging, we can configure the equations with the following 3 operations
1. swap 2 rows
2. multiply one row by a constant value
3. add (subtract) the multiple of one row onto another

using only these 3 operations ensures that the solutions to the system does not change

we move one row to the top, and divide the entire row by the coefficient of the first variable, making it equal to 1
next we subtract the multiple of the first row from all the rest so that all but the first varibel on  row 1 has been deleted 
from their respective equations

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ar array

const int maxN = 1e3 + 1,maxM = 0,maxK = 0,INF = 1e9, MOD = 1e9 + 7;

const double eps = 1e-6;

int N;
double arr[maxN][maxN];

void setIO(string name=""){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int gauss(){
    int r = 0, c = 0;
    for (c;c < N;c++){
        // it is said that the row that is swaped to the top should have the largest abs value, 
        // but what does that do?
        int t = r;
        for (int i=r;i<N;i++){
            if (fabs(arr[i][c]) > fabs(arr[t][c])) t = i;
        }

        // if even the largest coefficient is still 0, we simply move on
        if (fabs(arr[t][c]) < eps) continue;

        // swap the rows
        for (int i=c;i<N+1;i++) swap(arr[t][i], arr[r][i]);
        double a = arr[r][c];
        for (int i=c;i<N+1;i++) arr[r][i] /= a;
        for (int i=r+1;i<N;i++){
            if (fabs(arr[i][c]) < eps) continue;
            a = arr[i][c];
            for (int j=c;j<N+1;j++) arr[i][j] -= a * arr[r][j];
        }
        r += 1;
    }
    // this system of equation can produce one of three results: 
    // 1. one set of solution
    // 2. no solutions (0 = non-0)
    // 3. infinite solutions (0 = 0)
    if (r < N){
        // the rows with the smallest coefficients will get pushed to the bottom
        // under the condition r < N, the remaining row must all be 0s (c has iterated all N coefficients and thus everything below it would equal 0)
        for (int i=r;i<N;i++){
            if (fabs(arr[i][N]) > eps){
                // no solutions
                return 2;
            }
        }
        // infinite solutions
        return 1;
    }
    // one set of solutions
    return 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //setIO();

    cin >> N;
    for (int i=0;i<N;i++) for (int j=0;j<N+1;j++) cin >> arr[i][j];
    int res = gauss();
    if (res == 2){
        cout << "No solution\n";
    } else if (res == 1){
        cout << "Infinite group solutions\n";
    } else {
        for (int i=N-1;i>=0;i--){
            for (int j=i+1;j<N;j++){
                arr[i][N] -= arr[i][j] * arr[j][N];
            }
        }
        cout.precision(2);
        cout << fixed;
        for (int i=0;i<N;i++) cout << (fabs(arr[i][N]) < eps ? 0.00 : arr[i][N]) << '\n';
    }
    return 0;
}   