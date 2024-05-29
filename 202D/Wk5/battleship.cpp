#include <bits/stdc++.h>
using namespace std;

int n, m, arr[1001][1001];

bool bfs(int sx, int sy) {
    int width=0, height=0, count=1, curx, cury, nextx, nexty, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
    queue<pair<int, int>> q;

    for (int i=sy; i<m; i++) {
        if (arr[sx][i]==0) {
            width++;
        }
        else {
            break;
        }
    }

    for (int i=sx; i<n; i++) {
        if (arr[i][sy]==0) {
            height++;
        }
        else {
            break;
        }
    }

    q.push({sx, sy});
    arr[sx][sy] = 1;

    while (!q.empty()) {
        curx = q.front().first;
        cury = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            nextx = curx + dx[i];
            nexty = cury + dy[i];

            if (nextx>-1 && nexty>-1 && nextx<n && nexty<m) {
                if (arr[nextx][nexty] == 0) {
                    count++;
                    arr[nextx][nexty] = 1;
                    q.push({nextx, nexty});
                }
            }
        }
    }

    if (count == height*width) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string temp;
    int ans=0;
    bool val;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> temp;
        for (int j=0; j<m; j++) {
            if (temp[j] == '.') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 0) {
                val = bfs(i, j);
                if (!val) {
                    cout << "Bad placement.";
                    return 0;
                }
                else {
                    ans++;
                }
            }
        }
    }

    cout << "There are " << ans << " ships.";
}