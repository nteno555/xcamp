#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int MXN = 3005;
int n, m, a, b, k, ans;
vector<int> adj[MXN];
bool visited[MXN], closed[MXN];

void dfs(int node) {
    visited[node] = true;
    for (int x: adj[node]) {
        if (!closed[x] && !visited[x]) {
            dfs(x);
        }
    }
}

void count_comps() {
    ans = 0;
    for (int i=1; i<=n; i++) {
        if (!closed[i] && !visited[i]) {
            dfs(i);
            ans++;
        }
    }
    if(ans > 1) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}

int main() {
    cin >> n >> m;
    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<n; i++) {
        count_comps();
        cin >> k;
        closed[k] = true;
        for (int i=1; i<=n; i++) {
            visited[i] = false;
        }
    }
    return 0;
}