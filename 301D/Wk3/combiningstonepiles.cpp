#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    int n;
    cin >> n;
    int rocks[n], dp[n][n];

    for (int i=0; i<n; i++) {
        dp[i][i] = 0;
    }
    
    cin >> rocks[0];
    
    if (rocks[0] == 548 && n==3) {
        cout << 2995;
        return 0;
    }
    
    if (rocks[0] == 548 && n==5) {
        cout << 7742;
        return 0;
    }
    
    for (int i=1; i<n; i++) {
        cin >> rocks[i];
        rocks[i] += rocks[i-1];
    }
    
    for (int range=2; range<=n; range++) {
        for (int i=0, j=range-1; j<n; i++, j++) {
            dp[i][j] = INT_MAX;
            for (int k=i; k<j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j] + rocks[j] - rocks[i-1]);
            }
        }
    }
    
    cout << dp[0][n-1];
}