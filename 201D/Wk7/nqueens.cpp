#include <iostream>
using namespace std;

int n, total=0;
int board[12][12];

bool valid(int x, int y) {
    if (x < 0 || y < 0 || y > n || x > n) return false;
    for (int i = 0; i < y; i++) {
        if (board[x][i] == 1) {
            return false;
        }
    }
    for (int i=1; i<=min(x,y); i++) {
        if (board[x-i][y-i] == 1) {
            return false;
        }
    }
    for (int i=1; i<=min(n-x-1,y); i++) {
        if (board[x+i][y-i] == 1) {
            return false;
        }
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
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            board[i][j] = 0;
        }
    }
    dfs(0);
    cout << total;
    return 0;
}