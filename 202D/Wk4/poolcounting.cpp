#include <bits/stdc++.h>
using namespace std;

int n, m, arr[101][101];

void bfs(int sx, int sy) {
    int cx, cy;
    pair<int, int> temp;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    arr[sx][sy] = 2;
    int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
    int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

    while (!q.empty()) {
        temp = q.front();
        cx = temp.first;
        cy = temp.second;

        for (int i=0; i<8; i++) {
            if (cx+dx[i]>-1 && cy+dy[i]>-1 && cx+dx[i]<n && cy+dy[i]<m) {
                if (arr[cx+dx[i]][cy+dy[i]] == 1) {
                    q.push({cx+dx[i], cy+dy[i]});
                    arr[cx+dx[i]][cy+dy[i]] = 2;
                }
            }
        }
        
        q.pop();
    }
}

int main() {
    int count=0;
    string temp;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> temp;

        for (int j=0; j<m; j++) {
            if (temp[j] == '1') {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 1) {
                bfs(i, j);
                count++;
            }
        }
    }
    
    cout << count;
}