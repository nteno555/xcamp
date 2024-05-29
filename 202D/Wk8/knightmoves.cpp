#include <bits/stdc++.h>
using namespace std;

struct QInfo {
    int x;
    int y;
    int count;
}

int main() {
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[8] = {2, -2, 2, -2, 1, -1, 1, -1}, n, tempX, tempY, startX, startY, endX, endY, curEndX, curEndY, curStartX, curStartY, curStartCount, curEndCount;
    cin >> n >> startX >> startY >> endX >> endY;

    queue<QInfo> q1, queue<QInfo> q2;
    bool vis1[n][n], vis2[n][n];

    q1.push({startX, startY, 0});
    q2.push({endX, endY, 0});

    while (!q1.empty() && !q2.empty()) {
        curStartX = q1.front().x;
        curStartY = q1.front().y;
        curStartCount = q1.front().count;
        curEndX = q2.front().x;
        curEndY = q2.front().y;
        curStartCount = q2.front().count;

        q1.pop();
        q2.pop();

        for (int i=0; i<8; i++) {
            tempX = curStartX + dx[i];
            tempY = curStartY + dy[i]
            if (tempX < n && tempX > -1 && tempY < n && tempX > -1) {
                if (vis2[tempX][tempY]) {
                    cout << curStartCount + curEndCount;
                    return 0;
                }
                if (!vis1[tempX][tempY]) {
                    vis[tempX][tempY] = true;
                    q1.push({tempX, tempY, curStartCount+1});
                }
            }
        }

        for (int i=0; i<8; i++) {
            tempX = curEndX + dx[i];
            tempY = curEndY + dy[i];
            if (tempX < n && tempX > -1 && tempY < n && tempY > -1) {
                if (vis1[tempX][tempY]) {
                    cout << curStartCount + curEndCount + 1;
                    return 0;
                }
            }
            if (!vis[tempX][tempY]) {
                vis[tempX][tempY] = true;
                q1.push({tempX, tempY, curEndCount+1});
            }
        }
    }

    cout << -1;
    return 0;
}