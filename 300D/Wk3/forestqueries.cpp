#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
    int n, q, arr[1001][1001];
    char a;
    cin >> n >> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a;
            if (a == '*') arr[i+1][j+1] = 1;
            else arr[i+1][j+1] = 0;
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    int x1, x2, y1, y2;

    for (int i=0; i<q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1] << "\n";
    }
}