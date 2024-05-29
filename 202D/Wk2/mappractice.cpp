#include <bits/stdc++.h>

int main() {
    int n, sum, ans;
    map<int, int> m;

    cin >> n >> sum;
    int arr[n];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        map[arr[i]] = sum-arr[i];
    }

    for (int i=0; i<n; i++) {
        if (map[arr[i]].count()) {
            cout << i << ' ' << map[arr[i]].count() << endl;
        }
    }
}