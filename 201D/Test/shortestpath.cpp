#include <iostream>
using namespace std;

int n;
int count = 0;
int mountain = -1;
int beach = -1;
int maze[6][6];
int visited[6][6];

void floodfill(int x, int y) {
    if (maze[x][y] == 1 || x >= n || y >= n || x < 0 || y < 0 || visited[x][y] == 1) {
        return;
    }
    else if (maze[x][y] == 4) {
        if (beach == -1) {
            beach = count;
        }
        else {
            beach = min(count, beach);
        }
        return;
    }
    else if (maze[x][y] == 3) {
        if (mountain == -1) {
            mountain = count;
        }
        else {
            mountain = min(count, mountain);
        }
        return;
    }
    else {
        visited[x][y] = 1;
        count++;
        floodfill(x-1, y);
        floodfill(x, y-1);
        floodfill(x, y+1);
        floodfill(x+1, y);
        visited[x][y] = 0;
        count--;
    }
}

int main() {
    int startX, startY;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char charac;
            cin >> charac;
            if (charac == '.'){
                maze[i][j] = 0;
            }
            else if (charac == 'X') {
                maze[i][j] = 1;
            }
            else if (charac == 'M') {
                maze[i][j] = 3;
            }
            else if (charac == 'B') {
                maze[i][j] = 4;
            }
            else {
                startX = i;
                startY = j;
            }
        }
    }
    floodfill(startX, startY);
    if (mountain < beach) {
        cout << "Mountains " << mountain;
    }
    else if (mountain == beach) {
        cout << "Either " << mountain;
    }
    else {
        cout << "Beach " << beach;
    }
}