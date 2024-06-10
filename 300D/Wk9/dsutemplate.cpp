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
    
    //     int getRoots() {
    //     set<int> s;
    //     int ans=0;
    //     for (int i: e) {
    //         if (!s.count(i)) {
    //             ans++;
    //             s.insert(i);
    //         }
    //     }
    //     return ans;
    // }

};

int main() {
    FASTIO;
}