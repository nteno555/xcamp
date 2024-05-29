#include <iostream>
using namespace std;

int n;
int pathLength = -1;
int pathCount = 0;
int count = 1;
int maze[50][50];

void floodfill(int x, int y) {
    if (maze[x][y] != 0 || x >= n || y >= n || x < 0 || y < 0) {
        return;
    }
    if (x == n-1 && y == n-1) {
        if (pathLength == -1) {
            pathCount = 1;
            pathLength = count;
        }
        else {
            if (count == pathLength) {
                pathCount++;
            }
            else if (pathLength > count){
                pathLength = count;
                pathCount = 1;
            }
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
        maze[x][y] = 0;
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
    cout << pathCount << endl << pathLength;
}