#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    int n;
    cin >> n;
    int triangle[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            triangle[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            cin >> triangle[i][j];
        }
    }

    for (int i=n-2; i>0; i--) {
        for (int j=0; j<i+1; j++) {
            triangle[i][j] += max(triangle[i+1][j+1], triangle[i+1][j]);
        }
    }
    if (n>1) triangle[0][0] += max(triangle[1][0], triangle[1][1]);
    cout << triangle[0][0];
}