#include <iostream>
using namespace std;

int n, ans = 0, a=1;

void dfs(int sum) {
    if (sum == n) {
        ans++;
        return;
    }
    for (int i=a; i<n; i++) {
        dfs(sum+i);
    }
    return;
}

int main() {
    cin >> n;
    dfs(0);
    cout << ans;
    return 0;
}