#include <iostream>
using namespace std;

int n;
int count = 1;
int bestPath = -1;
int maze[11][11];

void floodfill(int x, int y) {
    if (maze[x][y] != 0 || x >= n || y >= n || x < 0 || y < 0) {
        return;
    }
    if (x == n-1 && y == n-1) {
        if (bestPath == -1) {
            bestPath = count;
        }
        else {
            bestPath = min(count, bestPath);
        }
        return;
    }
    else {
        maze[x][y] = 2;
        count++;
        floodfill(x-1, y);
        floodfill(x, y-1);
        floodfill(x, y+1);
        floodfill(x+1, y);
        visited[x][y] = 0;
        count--;
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    floodfill(0, 0);
    cout << bestPath;
}