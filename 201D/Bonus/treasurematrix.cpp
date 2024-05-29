#include <iostream>
using namespace std;

int maze[7][7];
int visited[7][7];
int n, m, count;
int maxTreasure = -1;

bool valid(int x, int y) {
    return (x>-1 && y>-1 && x<n && y<m && visited[x][y] != 1 && maze[x][y] != -1);
}

void dfs(int x, int y) {
    if (valid(x, y)) {
        if (x == n-1 && y == m-1) {
            maxTreasure = max(maxTreasure, count+maze[x][y]);
            return;
        }
        if (maze[x][y] > 0) {
            count = count + maze[x][y];
        }
        visited[x][y] = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i=0; i<4; i++) {
            dfs(x+dx[i], y+dy[i]);
        }
        visited[x][y] = 0;
        if (maze[x][y] > 0) {
            count = count - maze[x][y];
        }
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
            if (temp[j] == '#') maze[i][j] = -1;
            else if (temp[j] == '*') maze[i][j] = 0;
            else {
                maze[i][j] = temp[j] - '0';
            }
        }
    }
    dfs(0, 0);
    cout << maxTreasure;
    return 0;
}