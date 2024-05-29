#include <iostream>
using namespace std;

int n, m, visited[26], arr[21][21], curCount=0, ans=0;

void floodfill(int x, int y) {
    if (curCount>=26) {
        ans = 26;
        return;
    }
    if (x < 0 || y > 0 || x >= n || y >= m) {
        ans = max(ans, curCount);
        return;
    }
    if (visited[arr[x][y]] == 1) {
        ans = max(ans, curCount)
        return;
    }

    visited[arr[x][y]] = 1;
    curCount++;

    floodfill(x+1, y);
    floodfill(x-1, y);
    floodfill(x, y+1);
    floodfill(x, y-1);

    visited[arr[x][y]] = 0;
    curCount--;
}

int main() {
    string temp;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> temp;
        for (int j=0; j<m; j++) {
            if (temp[j] == 'A') arr[i][j] = 0;
            else if (temp[j] == 'B') arr[i][j] = 1;
            else if (temp[j] == 'C') arr[i][j] = 2;
            else if (temp[j] == 'D') arr[i][j] = 3;
            else if (temp[j] == 'E') arr[i][j] = 4;
            else if (temp[j] == 'F') arr[i][j] = 5;
            else if (temp[j] == 'G') arr[i][j] = 6;
            else if (temp[j] == 'H') arr[i][j] = 7;
            else if (temp[j] == 'I') arr[i][j] = 8;
            else if (temp[j] == 'J') arr[i][j] = 9;
            else if (temp[j] == 'K') arr[i][j] = 10;
            else if (temp[j] == 'L') arr[i][j] = 11;
            else if (temp[j] == 'M') arr[i][j] = 12;
            else if (temp[j] == 'N') arr[i][j] = 13;
            else if (temp[j] == 'O') arr[i][j] = 14;
            else if (temp[j] == 'P') arr[i][j] = 15;
            else if (temp[j] == 'Q') arr[i][j] = 16;
            else if (temp[j] == 'R') arr[i][j] = 17;
            else if (temp[j] == 'S') arr[i][j] = 18;
            else if (temp[j] == 'T') arr[i][j] = 19;
            else if (temp[j] == 'U') arr[i][j] = 20;
            else if (temp[j] == 'V') arr[i][j] = 21;
            else if (temp[j] == 'W') arr[i][j] = 22;
            else if (temp[j] == 'X') arr[i][j] = 23;
            else if (temp[j] == 'Y') arr[i][j] = 24;
            else if (temp[j] == 'Z') arr[i][j] = 25;
        }
    }

    floodfill(0, 0);
    
    cout << count;
}