#include <iostream>
using namespace std;

int n;

int exponent() {
    int ans = 1;
    for (int i=0; i<n; i++) {
        ans = ans * 2;
    }
    return ans;
}

int main() {
    cin >> n;
    cout << exponent() - 1;
    return 0;
}