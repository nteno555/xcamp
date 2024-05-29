#include <iostream>
#include <queue>
using namespace std;

int coins[101];
int visited[1000001];
int n, sum, ans=-1;

void bfs() {
    queue<int> q;
    queue<int> counts;
    int cur, count=1;
    for (int i=0; i<n; i++) {
        if (coins[i] == ans) {
            ans = 1;
            return;
        }
        q.push(coins[i]);
        counts.push(count);
        visited[coins[i]] = 1;
    }
    while (!q.empty()) {
        cur = q.front();
        count = counts.front(); 
        for (int i=0; i<n; i++) {
            if (cur+coins[i] == sum) {
                ans = count + 1;
                return;
            }
            if (visited[cur+coins[i]] != 1) {
                visited[cur+coins[i]] = 1;
                q.push(cur+coins[i]);
                counts.push(count+1);
            }
        }
        q.pop();
    }
}

int main() {
    cin >> n >> sum;

    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }

    bfs();

    cout << ans;
}