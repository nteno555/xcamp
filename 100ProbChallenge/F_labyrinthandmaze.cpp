#include <bits/stdc++.h>
using namespace std;

int n, shortest=INT_MAX, shortestCount=0, maze[50][50];

void dfs(int x, int y, int count) {
    if (x==n-1 && y==n-1) {
        if (shortest==count) {
            shortestCount++;
            return;
        }
        shortest = min(count, shortest);
        shortestCount = 1;
    }
    if (count > shortest) return;
    if (x < 0 || y < 0 || x >=n || y >= n || maze[x][y] != 0) return;

    maze[x][y] = 2;
    dfs(x, y+1, count+1);
    dfs(x, y-1, count+1);
    dfs(x+1, y, count+1);
    dfs(x-1, y, count+1);
    maze[x][y] = 0;
}

int main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }

    dfs(0, 0, 1);

    cout << shortestCount << endl << shortest;
} 