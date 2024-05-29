#include <iostream>
using namespace std;

int n, startX, startY, count;
int maze[201][201];
int visited[201][201];

bool valid(int x, int y) {
    return (maze[x][y] == 0 && x < n && y < n && y > -1 && x > -1 && visited[x][y] == 0);
}

void floodfill(int x, int y) {
    if (valid) {
        visited[x][y] = 1;
        count++;
        floodfill(x-1, y);
        floodfill(x+1, y);
        floodfill(x, y-1);
        floodfill(x, y+1);
    }
    return;
}

int main() {
    string temp;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> temp;
        for (int j=0; j<n; j++) {
            if (temp[j] == '_') {
                maze[i][j] = 0;
            }
            else if (temp[j] == '-') {
                maze[i][j] = 1;
            }
            else {
                startX = i;
                startY = j;
                maze[i][j] = 0;
            }
        }
    }
    floodfill(startX, startY)
}