#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

struct DSU{
    vector<int> e;
    DSU(int n) {e = vector<int> (n+1, -1); }

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
};

int main() {
    FASTIO;
    int n, m, a, b, c;
    bool t;
    cin >> n >> m;
    DSU s(n);
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        if (a==1) {
            s.unite(b, c);
        }
        else {
            t = s.sameSet(b, c);
            if (t) cout << "Y\n";
            else cout << "N\n";
        }
    }
}