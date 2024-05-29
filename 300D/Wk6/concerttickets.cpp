#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    int tickets, customers, c, a, ticketPrice;
    vector<int> v;
    cin >> tickets >> customers;
    for (int i=0; i<tickets; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for (int i=0; i<customers; i++) {
        cin >> c;
        ticketPrice = upper_bound(v.begin(), v.end(), c) - v.begin() - 1;
        if (ticketPrice == -1) {
            cout << -1 << "\n";
        }
        else if (v[ticketPrice] <= c) {
            cout << v[ticketPrice] << "\n";
            v.erase(ticketPrice + v.begin());
        }
        else {
            cout << -1 << "\n";
        }
    }
}