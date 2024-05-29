#include <iostream>
using namespace std;

bool maze[50][50];
int n, m;
int mostTrash = -1;
int count = 0;

bool valid(int x, int y){
    return (x>-1 && y>-1 && x<n && y<m && maze[x][y]);
}

void dfs(int x, int y) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    if (valid(x, y)) {
        maze[x][y] = false;
        count++;
        for (int i=0; i<4; i++) {
            dfs(x+dx[i], y+dy[i]);
        }
        if (mostTrash == -1) mostTrash = count;
        else mostTrash = max(mostTrash, count);
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
            if (temp[j] == '1') maze[i][j] = true;
            else maze[i][j] = false;
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j]) {
                count = 0;
                dfs(i, j);
            }
        }
    }

    cout << mostTrash;
}