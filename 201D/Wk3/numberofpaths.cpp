#include <iostream>
using namespace std;

int n;
int count = 0;
int maze[11][11];
int visited[11][11];

void floodfill(int x, int y) {
    if (maze[x][y] == 1 || x >= n || y >= n || x < 0 || y < 0 || visited[x][y] == 1) {
        return;
    }
    if (x == n-1 && y == n-1) {
        count++;
        return;
    }
    else {
        visited[x][y] = 1;
        floodfill(x-1, y);
        floodfill(x, y-1);
        floodfill(x, y+1);
        floodfill(x+1, y);
        visited[x][y] = 0;
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
    cout << count;
}