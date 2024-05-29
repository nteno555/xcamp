#include <iostream>
using namespace std;

int n, m, count;
// red is 0, blue is 1
int maze[16][16];

void dfs(int x, int y) {
    if(x>=n || y>=m || x<0 || y<0) {
        return;
    }
    if(x==n-1 && y==m-1) {
        count++;
        return;
    }
    

    for(int i=1; i<n-x; i++) {
        for(int j=1; j<m-y; j++) {
            if (maze[x+i][y+j] != maze[x][y]) dfs(x+i, y+j);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char letter;
            cin >> letter;
            if (letter == 'R') {
                maze[i][j] = 0;
            }
            else maze[i][j] = 1;
        }
    }
    
    dfs(0, 0);
    cout << count;
}