#include <iostream>
using namespace std;

int n, startX, startY, endX, endY;
int maze[11][11];
bool foundPath = false;

void floodfill(int x, int y) {
    if (maze[x][y] != 0 || x >= n || y >= n || x < 0 || y < 0) {
        return;
    }
    if (x == endX && y == endY) {
        foundPath = true;
    }
    else {
        maze[x][y] = 2;
        floodfill(x-1, y);
        floodfill(x, y-1);
        floodfill(x, y+1);
        floodfill(x+1, y);
    }
}

int main() {
    cin >> n >> startX >> startY >> endX >> endY;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    floodfill(startX, startY);
    if (foundPath) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
