#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
    int n, sum, coinVal;
    cin >> n >> sum;
    int mins[sum+1], coins[n+1];
    
    for (int i=0; i<=sum; i++) mins[i] = -1;
    
    for (int i=0; i<n; i++) {
        cin >> coins[i];
        if (coins[i] <= sum) mins[coins[i]] = 1;
    }

    for (int i=1; i<sum; i++) {
        if (mins[i] != -1){
            for (int j=0; j<n; j++) {
                coinVal = coins[j];
                if (i + coinVal <= sum) {
                    if (mins[i+coinVal] == -1) mins[i+coinVal] = mins[i] + 1;
                    mins[i+coins[j]] = min(mins[i+coins[j]], mins[i] + 1);
                }
            }
        }
    }
    
    cout << mins[sum];
}