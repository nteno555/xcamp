#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    int n, h, p, s, ans=0;
    char a;
    cin >> n;
    int arr[n+1][3] = {0};
    // H - 1
    // P - 2
    // S - 3

    for (int i=0; i<n; i++) {
        cin >> a;
        if (a=='H') arr[i][0]++;
        else if (a=='P') arr[i][1]++;
        else arr[i][2]++;

        if (i) {
            arr[i][0] += arr[i-1][0];
            arr[i][1] += arr[i-1][1];
            arr[i][2] += arr[i-1][2];
        }
    }

    h = arr[n-1][0];
    p = arr[n-1][1];
    s = arr[n-1][2];

    for (int i=0; i<n; i++) {
        ans = max(ans, arr[i][0] + max(p-arr[i][1], s-arr[i][2]));
        ans = max(ans, arr[i][1] + max(h-arr[i][0], s-arr[i][2]));
        ans = max(ans, arr[i][2] + max(h-arr[i][0], p-arr[i][1]));
    }

    cout << ans;
}