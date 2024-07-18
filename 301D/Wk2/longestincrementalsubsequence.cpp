#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    int n, x, maxSoFar = 1;
    vector<pair<int, int>> v;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x;
        v.push_back({x, 1});
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (v[j].first < v[i].first) {
                v[i].second = max(v[j].second+1, v[i].second);
            }
        }
        maxSoFar = max(v[i].second, maxSoFar);
    }

    cout << maxSoFar;
}