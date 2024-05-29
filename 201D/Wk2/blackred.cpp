#include <iostream>
using namespace std;

int w, h, sx, sy, count;
int maze[20][20];
int visited[20][20];

void floodfill(int x, int y) {
    if (maze[x][y] == 1 || x >= h || y >= w || x < 0 || y < 0 || visited[x][y] == 1) {
        return;
    }
    visited[x][y] = 1;
    count++;
    floodfill(x-1, y);
    floodfill(x+1, y);
    floodfill(x, y-1);
    floodfill(x, y+1);
}

int main(){
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        count = 0;
        for (int i=0; i<20; i++) {
            for (int j=0; j<20; j++) {
                visited[i][j] = 0;
            }
        }
        for (int i=0; i<h; i++) {
            string temp;
            cin >> temp;
            for (int j=0; j<w; j++) {
                if (temp[j] == '.') {
                    maze[i][j] = 0;
                }
                else if (temp[j] == '@'){
                    maze[i][j] = 0;
                    sx = i;
                    sy = j;
                }
                else {
                    maze[i][j] = 1;
                }
            }
        }
        floodfill(sx, sy);
        cout << count << " ";
    }
}