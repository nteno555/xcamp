#include <iostream>
using namespace std;

int n, paths=0;
int field[12][2];
int visited[2000][2000];


void dfs(int x, int y, int dir, int count) {
    // if (count == n)
    if (visited[1000+x][1000+y] == 1) {
        // cout << "RETURNED " << x << ' ' << y << ' ' << count << endl;
        return;
    }
    if (count==n) {
        if (dir==0 && x == 0 && y < 0) paths++;
        if (dir==1 && x < 0 && y == 0) paths++;
        if (dir==2 && x == 0 && y > 0) paths++;
        if (dir==3 && x > 0 && y == 0) paths++;
        return;
    }
    // 0: up
    // 1: right
    // 2: down
    // 3: left
    if (dir==0) {
        for (int i=0; i<n; i++) {
            if (field[i][0] == x && field[i][1] > y) {
                // cout << "dir: " << dir << ", " << x << ' ' << y << ", " << field[i][0] << ' ' << field[i][1] << ", " << count << endl;
                visited[1000+x][1000+y] = 1;
                dfs(field[i][0], field[i][1], 1, count+1);
                dfs(field[i][0], field[i][1], 2, count+1);
                dfs(field[i][0], field[i][1], 3, count+1);
                visited[1000+x][1000+y] = 0;
            }
        }
        return;
    }
    if (dir==1) {
        for (int i=0; i<n; i++) {
            if (field[i][0] > x && field[i][1] == y) {
                // cout << "dir: " << dir << ", " << x << ' ' << y << ", " << field[i][0] << ' ' << field[i][1] << ", " << count << endl;
                visited[1000+x][1000+y] = 1;
                dfs(field[i][0], field[i][1], 0, count+1);
                dfs(field[i][0], field[i][1], 2, count+1);
                dfs(field[i][0], field[i][1], 3, count+1);
                visited[1000+x][1000+y] = 0;
            }
        }
    }
    if (dir==2) {
        for (int i=0; i<n; i++) {
            if (field[i][0] == x && field[i][1] < y) {
                // cout << "dir: " << dir << ", " << x << ' ' << y << ", " << field[i][0] << ' ' << field[i][1] << ", " << count << endl;
                visited[1000+x][1000+y] = 1;
                dfs(field[i][0], field[i][1], 0, count+1);
                dfs(field[i][0], field[i][1], 1, count+1);
                dfs(field[i][0], field[i][1], 3, count+1);
                visited[1000+x][1000+y] = 0;
            }
        }
    }
    if (dir==3) {
        for (int i=0; i<n; i++) {
            if (field[i][0] > x && field[i][1] == y) {
                // cout << "dir: " << dir << ", " << x << ' ' << y << ", " << field[i][0] << ' ' << field[i][1] << ", " << count << endl;
                visited[1000+x][1000+y] = 1;
                dfs(field[i][0], field[i][1], 0, count+1);
                dfs(field[i][0], field[i][1], 1, count+1);
                dfs(field[i][0], field[i][1], 2, count+1);
                visited[1000+x][1000+y] = 0;
            }
        }
    }
    return;
    }

int main(){ 
    cin >> n;
    int x, y;

    for (int i=0; i<n; i++) {
        cin >> x >> y;
        field[i][0] = x;
        field[i][1] = y;
    }

    dfs(0, 0, 0, 0);
    dfs(0, 0, 1, 0);
    dfs(0, 0, 2, 0);
    dfs(0, 0, 3, 0);

    cout << paths;

    return 0;
}