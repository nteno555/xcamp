#include <iostream>
using namespace std;

int n, total=0;
int board[10][10];

bool valid(int x, int y) {
    if (x<0 || y<0 || x>=n || y>=n) return false;
    for (int i=0; i<n; i++) {
        if (board[x][i] == 1 || board[i][y] == 1) return false;
    }
    return true;
}

void dfs(int col) {
    if (col == n) {
        total++;
        return;
    }

    for (int i=0; i<n; i++) {
        if (valid(i, col)) {
            board[i][col] = 1;
            dfs(col+1);
            board[i][col] = 0;
        }
    }

    return;
}

int main() {
    cin >> n;
    dfs(0);
    cout << total;
}