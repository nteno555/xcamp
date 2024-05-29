#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
    int n, k, x1, y1, x2, y2, ans=0, arr[1001][1001];

    cin >> n >> k;

    for (int i=0; i<1001; i++) {
        for (int j=0; j<1001; j++) arr[i][j]=0;
    }

    for (int i=0; i<n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        arr[x1][y1]++;
        arr[x1][y2]--;
        arr[x2][y1]--;
        arr[x2][y2]++;
    }

    for (int i=0; i<1001; i++) {
        for (int j=0; j<1001; j++) {
            if (i) arr[i][j] += arr[i-1][j];
            if (j) arr[i][j] += arr[i][j-1];
            if (i && j) arr[i][j] -= arr[i-1][j-1]; 

            if (arr[i][j] == k) { 
                ans++;
            }
        }
    }

    cout << ans;
}