#include <iostream>
using namespace std;

int maze[101][101];
int r, c, count;
int longest = -1;

bool valid(int x, int y) {
    return (x>-1 && y>-1 && x<r && y<c);
}

void dfs(int x, int y) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    if (valid(x, y)) {
        count++;

        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (maze[x+dx[i]][y+dy[j]] < maze[x][y]) {
                    dfs(x+dx[i], y+dy[j]);
                }
            }
        }
    }
    else return;
}

int main(){
    cin >> r >> c;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            count = 0;
            dfs(i, j);
            longest = max(longest, count);            
        }
    }
}