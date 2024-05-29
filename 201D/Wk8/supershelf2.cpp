#include <iostream>
#include <limits.h>
using namespace std;

int n, shelf, ans=INT_MAX;
int heights[20], visited[20];

void dfs(int level, int sum) {
    if (sum > shelf) {
        ans = min(ans, sum);
        return;
    }
    for (int i=0; i<n; i++) {
        if (visited[i] != 1) {
            visited[i] = 1;
            dfs(level+1, sum+heights[i]);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n >> shelf;
    for (int i=0; i<n; i++) {
        cin >> heights[i];
    }
    return 0;
}