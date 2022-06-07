// try to fit both BFS into one function instead of two

#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ar array

const int maxN = 1e3;

int n,m,p[maxN][maxN],d1[maxN][maxN],d2[maxN][maxN],dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
bool visited1[maxN][maxN],visited2[maxN][maxN];
char g[maxN][maxN], dc[4] = {'D','R','U','L'};
vector<char> ch;
priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
ar<int,2> A;

bool e(int i, int j,bool visited[maxN][maxN]){
    return -1<i&&i<n&&-1<j&&j<m&&g[i][j] != '#'&&(!visited[i][j]);
}

