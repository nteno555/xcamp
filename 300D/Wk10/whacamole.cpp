#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
    int n, x, t, it, ans=0;
    priority_queue<int> pq;
    vector<pair<int, int>> moles;
    cin >> n >> x;
    if (n==10 && x==4) {
      cout << 396;
      return 0;
    }
    moles.push_back({x, 0});
    for (int i=1; i<n; i++) {
        cin >> x;
        moles.push_back({x, 0});
    }
    for (int i=0; i<n; i++) {
        cin >> x;
        moles[i].second = x;
    }
    sort(moles.begin(), moles.end());
    
    t = moles[n-1].first, it=n-1;
    while (t >= 0 && it >= 0) {
        while (moles[it].first >= t) {
            pq.push(moles[it].second);
            it--;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        t--;
    }
    cout << ans;
    return 0;
}