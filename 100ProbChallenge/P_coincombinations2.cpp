#include <iostream>
using namespace std;

int ls[1000001], coins[101];
int n, sum, prev=0;

int add(int a, int b) {
    int c = 1000000007 - a;
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

void dp() {
    for (int i=1; i<=sum; i++) {
        for (int j=0; j<n; j++) {
            if (coins[j] < i && coins[j] >= prev) {
                ls[i] = add(ls[i], ls[i-coins[j]]);
                prev = coins[j];
            }
        }

    }    
}

int main() {
    int temp;
    cin >> n >> sum;

    for (int i=0; i<1000001; i++) {
        ls[i] = 0;
    }

    for (int i=0; i<n; i++) {
        cin >> temp;
        coins[i] = temp;
        ls[temp] = 1;
    }

    sort(coins, sizeof(coins)/sizeof(coins[0]));

    dp();

    cout << ls[sum];

    return 0;
}