#include <iostream>
using namespace std;

int n, m;
int count = 1;
int bestPath = -1;
int maze[100][100];
int visited[100][100];

void floodfill(int x, int y) {
    if (maze[x][y] == 1 || x >= n || y >= n || x < 0 || y < 0 || visited[x][y] = 1) {
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
        visited[x][y] = 1;
        if (direction[pastDirection] != direction[pastDirection - 1]) {
            count++;
        }
        floodfill(x-1, y);
        floodfill(x, y-1);
        floodfill(x, y+1);
        floodfill(x+1, y);
        visited[x][y] = 0;
        if (direction[pastDirection] != direction[pastDirection - 1]) {
            count--;
        }
        pastDirection--;
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> maze[i][j];
        }
    }
    floodfill(0, 0);
    cout << bestPath;
}