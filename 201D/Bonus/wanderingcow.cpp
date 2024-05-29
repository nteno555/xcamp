#include <iostream>
using namespace std;

int n, m, t, r1, c1, r2, c2, paths;
bool maze[101][101];

bool valid(int x, int y) {
    return (x>-1 && y>-1 && x<n && y<m && maze[x][y]);
}

void dfs(int x, int y, int count) {
    if (count == t) {
        if (x == r2 && y == c2) {
            paths++;
        }
        return;
    }
    if (valid(x, y)) {
        // cout << x << ' ' << y << ' ' << count << endl;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i=0; i<4; i++) {
            dfs(x+dx[i], y+dy[i], count+1);
        }
    }
    return;
}

int main()
{
    cin >> n >> m >> t;
    for (int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        for (int j=0; j<m; j++) {
            if (temp[j] == '.') {
                maze[i][j] = true;
            }
            else maze[i][j] = false;
        }
    }
    
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << maze[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    cin >> r1 >> c1 >> r2 >> c2;
    maze[r1][c1] = true;
    dfs(r1, c1, 0);
    cout << paths;
    return 0;
}

// 14396412
// 6234334