#include <iostream>
using namespace std;

int n;
int maze[100][100]{};
int visted[100][100]{};

int floodFill(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 1 || visted[x][y] == 1) {
        return 0;
    }
    visted[x][y] = 1;
    return 1 + floodFill(x - 1, y) + floodFill(x + 1, y) + floodFill(x, y - 1) + floodFill(x, y + 1);
}

int main() {
    int a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    cout << floodFill(a - 1, b - 1);
    return 0;
}