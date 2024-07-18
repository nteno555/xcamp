#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

struct DSU{
    vector<int> e;
    DSU(int n) {
        e = vector<int> (n+1, -1); 
    }

    int get(int x) {
        return (e[x] < 0 ? x : e[x] = get(e[x]));
    }

    bool sameSet(int a, int b) {
        return (get(a) == get(b));
    }

    int size(int x) {
        return -e[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x==y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }

    int matches(vector<int> &v, int &n) {
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (get(v[i]) == i || v[i] == i) {
                ans++;
            } 
        }
        return ans;
    }
};

int main() {
    FASTIO;
    int n, m, x, y;
    cin >> n >> m;
    DSU d(n);
    vector<int> matches(n+1);
    for (int i=0; i<n; i++) {
        cin >> matches[i];
    }
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        d.unite(x, y);
    }
    cout << d.matches(matches, n);
}