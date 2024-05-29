#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m, rooms=0;
int arr[1001][1001];

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x > m || y > n) return;
    if (arr[x][y] != 0) return;

    arr[x][y] = 1;
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x y-1);
    dfs(x, y+1);

    return;
} 

int main() {
    string temp;

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> temp;
        for (int j=0; j<m; j++) {
            if (temp[j] == '#') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 0) {
                dfs(i, j);
                rooms++;
            } 
        }
    }

    cout << rooms;
}