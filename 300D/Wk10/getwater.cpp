#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
    long long n, a;
    cin >> n;
    vector<pair<long long, long long>> people;
    for (long long i=0; i<n; i++) {
        cin >> a;
        people.push_back({a, i});
    }
    
    sort(people.begin(), people.end());
    a=0;

    for (long long i=0; i<n; i++) {
        a += (n-i-1)*(people[i].first);
        cout << people[i].second+1 << ' ';
    }
    double b = double(a)/double(n);
    cout << "\n" << fixed << setprecision(2) << b;
}
