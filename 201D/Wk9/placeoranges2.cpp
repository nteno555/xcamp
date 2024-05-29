#include <iostream>
using namespace std;

int divisions, n, ans=0, cases;

void dfs(int level, int sum) {
    if (level == divisions) {
        if (sum == n) {
            ans++;
        }
        return;
    }
    for (int i=a; i<=n; i++) {
        dfs(level+1, sum+i);
    }
    return;
}

int main() {
    cin >> cases;
    for (int i=0; i<cases; i++) {
        ans = 0;
        cin >> n >> divisions;
        dfs(0, 0);
        cout << ans << endl;
    }
}