#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cx, cy, curCount;
    queue<pair<int, int>> q;
    queue<int> countq;
    pair<int, int> p;
    cin >> n;

    if (n==1) {
        cout << 0;
        return 0;
    }

    int arr[n][n], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    q.push({0, 0});
    countq.push(1);
    arr[0][0] = 2;

    while (!q.empty()) {
        p = q.front();
        cx = p.first;
        cy = p.second;
        curCount = countq.front();

        for (int i=0; i<4; i++) {
            if (cx+dx[i]>-1 && cy+dy[i]>-1 && cx+dx[i] < n && cy+dy[i] < n) {
                if (cx+dx[i] == n-1 && cy+dy[i] == n-1) {
                    cout << curCount+1;
                    return 0;
                }
                if (arr[cx+dx[i]][cy+dy[i]] == 0) {
                    countq.push(curCount+1);
                    arr[cx+dx[i]][cy+dy[i]] = 2;
                    q.push({cx+dx[i], cy+dy[i]});
                }
            }
        }

        q.pop();
        countq.pop();
    }

    cout << -1;
    return 0;
}