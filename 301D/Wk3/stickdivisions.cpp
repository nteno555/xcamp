#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    long long x, n, a, sum, ans=0;
    cin >> x >> n;
    priority_queue<long long> pq;
    for (long long i=0; i<n; i++) {
        cin >> a;
        pq.push(-a);
    }

    while (pq.size() >= 2) {
        sum = (-pq.top());
        pq.pop();
        sum += (-pq.top());
        pq.pop();
        pq.push(-sum);
        ans += sum;
    }

    cout << ans;
}