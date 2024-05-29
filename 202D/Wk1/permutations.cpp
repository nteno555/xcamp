#include <iostream>
using namespace std;

int n, ans=0;
arr[100000], visited[100000];

void dfs(int level) {
    visited[level] = 1;
    cout << level << ' ';
    
    for (int i=1; i<=n; i++) {
        if (visited[i] != 1) {
            dfs(i);
        }
    }

    cout << endl;

    visited[level] = 0;
    return;
}

int main() {
    cin >> n;
}