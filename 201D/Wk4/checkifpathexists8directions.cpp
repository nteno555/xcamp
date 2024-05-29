#include <iostream>
using namespace std;

int n, startX, startY, endX, endY;
int maze[11][11];
int visited[11][11];

bool valid(int x, int y) {
    return (maze[x][y] == 0 && x < n && y < n && y > -1 && x > -1 && visited[x][y] == 0);
}

bool floodfill(int x, int y) {
    if (x == endX && y == endY) {
        return true;
    }
    if (valid) {
        visited[x][y] = 1;
        return (floodfill(x-1, y) || floodfill(x+1, y) || floodfill(x, y-1) || floodfill(x, y+1));
    }
    return false;
}

int main() {
    cin >> n >> startX >> startY >> endX >> endY;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    bool foundPath = floodfill(startX, startY);
    if (foundPath) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
