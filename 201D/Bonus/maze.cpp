#include <iostream>
using namespace std;

bool maze[6][6];
int n, m, count;

bool valid(int x, int y) {
    return (maze[x][y] && x>-1 && y>-1 && x<n && y<m);
}

void floodfill(int x, int y) {
    if (valid(x, y)) {
        if (x == n-1 && y == m-1) {
            count++;
            return;
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        maze[x][y] = false;
        for (int i=0; i<4; i++) {
            floodfill(x+dx[i], y+dy[i])
        }
        maze[x][y] = true;
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        for (int j=0; j<m; j++) {
            if (temp[j] == '*') {
                maze[i][j] = true;
            }
            else {
                maze[i][j] = false;
            }
        }
    }
}