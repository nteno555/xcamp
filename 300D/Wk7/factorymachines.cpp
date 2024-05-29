#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false);
using namespace std;

vector<long long> machines;
long long n;

long long calcProducts(long long time) {
    long long ans = 0;
    for (long long i=0; i<n; i++) {
        ans += time/machines[i];
    }
    return ans;
}

int main() {
    long long desiredProducts, x, i=0, j=LLONG_MAX, mid;
    cin >> n >> desiredProducts;
    for (long long i=0; i<n; i++) {
        cin >> x;
        j = min(j, x);
        machines.push_back(x);
    }
    sort(machines.begin(), machines.end());

    j = j * desiredProducts;
    while (i<j) {
        mid = (i+j)/2;
        if (calcProducts(mid) < desiredProducts) {
            i = mid+1;
        }
        else {
            j = mid;
        }
    }
    cout << i;
    return 0;
}