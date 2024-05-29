#include <iostream>
using namespace std;

int n;
long long ls[200001];

long long alg() {
    long long cur = ls[0];
    long long ans = ls[0];
    for (int i=1; i<n; i++) {
        cur = max(cur + ls[i], ls[i]);
        ans = max(cur, ans);
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> ls[i];
    }

    cout << alg();
}