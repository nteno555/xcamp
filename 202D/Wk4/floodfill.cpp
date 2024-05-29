#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sx, sy, cx, cy, count=1;
    int dx[4] = {-1, 1, -1, 1};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    pair<int, int> temp;
    cin >> n >> sx >> sy;
    int arr[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    q.push({sx, sy});
    arr[sx][sy] = 2;

    while (!q.empty()) {
        temp = q.front();
        cx = temp.first;
        cy = temp.second;

        for (int i=0; i<4; i++) {
            if (cx+dx[i]>-1 && cy+dy[i]>-1 && cx+dx[i]<n && cy+dy[i]<n) {
                if (arr[cx+dx[i]][cy+dy[i]] == 0) {
                    arr[cx+dx[i]][cy+dy[i]] = 2;
                    // cout << cx+dx[i] << ", " << cy+dy[i] << endl;
                    q.push({cx+dx[i], cy+dy[i]});
                    count++;
                }
            }
        }
        
        q.pop();
    }

    cout << count;
}