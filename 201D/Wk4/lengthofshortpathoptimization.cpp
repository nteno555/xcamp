#include <iostream>
using namespace std;

int n, endX, endY;
int count = 1;
int bestPath = -1;
int maze[500][500];
int visited[500][500];

void floodfill(int x, int y) {
    if (maze[x][y] == 1 || x >= n || y >= n || x < 0 || y < 0 || visited[x][y] == 1) {
        return;
    }
    if (x == endX && y == endY) {
        if (bestPath == -1) {
            bestPath = count;
        }
        else {
            bestPath = min(count, bestPath);
        }
        return;
    }
    else {
        visited[x][y] = 1;
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
    int startX, startY;
    cin >> n >> startX >> startY >> endX >> endY;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    floodfill(startX, startY);
    cout << bestPath;
}g