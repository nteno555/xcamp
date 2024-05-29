#include <iostream>
using namespace std;

int n, m;
int count = 0;
int maze[100][100];

bool isValid(int x, int y) {
    return (x>-1 && y>-1 && x<n && y<m && maze[x][y] == 1);
}

void floodFill(int x, int y) {
    if (isValid(x, y)) {
        maze[x][y] = 2;
        floodFill(x-1, y+1);
        floodFill(x-1, y);
        floodFill(x-1, y+1);
        floodFill(x, y+1);
        floodFill(x, y-1);
        floodFill(x+1, y+1);
        floodFill(x+1, y);
        floodFill(x+1, y-1);
    }
    return;
}

int main() {
    cin >> n >> m;
    string temp;

    for (int i=0; i<n; i++) {
        cin >> temp;
        for (int j=0; j<m; j++) {
            if (temp[j] == '1') maze[i][j] = 1;
            else maze[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j] == 1) {
                count++;
                floodFill(i, j);
            }
        }
    }

    cout << count;
}