#include <iostream>
using namespace std;

int n, m, sx, sy;
int maze[501][501];
int visited[501][501];
int count = 1;

void floodfill(int x, int y) {
    if (maze[x][y] == 1 || x >= n || y >= m || x < 0 || y < 0 || visited[x][y] != 0) {
        return;
    }
    visited[x][y] = count;
    count ++;
    floodfill(x-1, y);
    floodfill(x, y-1);
    floodfill(x, y+1);
    floodfill(x+1, y);
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> maze[i][j];
        }
    }
    floodfill(0, 0);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}