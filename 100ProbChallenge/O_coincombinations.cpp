#include <iostream>
using namespace std;

int coins[101];
int ls[1000001];
int n, sum;

int add(int a, int b) {
    int c = 1000000007-a;
    if (b==c) {
        return 0;
    }
    if (b<c) {
        return a+b;
    }
    else {
        return b-c;
    }
}

void dfs() {
    for (int i=1; i<=sum; i++) {
        for (int j=0; j<n; j++) {
            if (coins[j] < i) {
                // cout << i << ": " << j << ", " << coins[j] << endl;
                ls[i] = add(ls[i], ls[i-coins[j]]);
            }
        }
        // cout << i << ": " << ls[i] << endl;
    }
}

int main() {
    int temp;
    cin >> n >> sum;

    for (int i=0; i<1000000; i++) {
        ls[i] = 0;
    }
    
    for (int i=0; i<100; i++) {
        coins[i] = 0;
    }

    for (int i=0; i<n; i++) {
        cin >> temp;
        coins[i] = temp;
        ls[temp] = 1;
    }

    dfs();
    // while (ls[sum] < 0) {
    //     ls[sum] = ls[sum] + 10000000007;
    // }
    cout << ls[sum]%10000000007;
}