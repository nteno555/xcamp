#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> x[1000000];
vis[1000000];

void dfs(int a) {
    if (x[a][0] == 0 || vis[a] == 1) {
        return;
    }
    int b=0;
    cout << x[a];
    vis[a] = 1;
    while (x[a][b] != 0) {
        dfs(x[a][b]);
    }
    vis[a] = 0;
}

int main() {
    int n;
    x[1] = {4, 5};
    x[2] = {1, 3};
    x[3] = {1};
    x[5] = {4};
}