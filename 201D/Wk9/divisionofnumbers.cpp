#include <iostream>
using namespace std;

int divisions, n, ans=0, a=1;

void dfs(int level, int sum) {
    if (level == divisions) {
        if (sum == n) {
            ans++;
        }
        return;
    }
    for (int i=a; i<=n-sum; i++) {
        a = i;
        dfs(level+1, sum+i);
        a = 1;
    }
    return;
}

int main() {
    cin >> n >> divisions;
    dfs(0, 0);
    cout << ans;
}
