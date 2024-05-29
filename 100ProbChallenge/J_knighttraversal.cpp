#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[401][401];
bool visited[401][401];

bool valid(int x, int y) {
    return (x>-1 && y>-1 && x<n && y<m && visited[x][y] == false);
}

void bfs(int sx, int sy) {
    queue<int> qx;
    queue<int> qy;
    queue<int> counterQueue;
    int currentX, currentY, curCount;
    int count = 0;
    int dx[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
    int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};
    qx.push(sx);
    qy.push(sy);
    counterQueue.push(count);
    
    if (curCount > n*m) return;

    while (!qx.empty()) {
        currentX = qx.front();
        currentY = qy.front();
        curCount = counterQueue.front();
        visited[currentX][currentY] = true;
        board[currentX][currentY] = curCount;
        qx.pop();
        qy.pop();
        counterQueue.pop();
        for (int i=0; i<8; i++) {
            if (valid(currentX+dx[i], currentY+dy[i])) {
                qx.push(currentX + dx[i]);
                qy.push(currentY + dy[i]);
                counterQueue.push(curCount+1);
                visited[currentX + dx[i]][currentY + dy[i]] = true;
            }
        }
    }

    return;
}

int main() {
    int x, y;
    cin >> n >> m >> x >> y;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            board[i][j] = -1;
            visited[i][j] = false;
        }
    }

    bfs(x-1, y-1);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

// 0    3    2    
// 3    -1   1    
// 2    1    4 