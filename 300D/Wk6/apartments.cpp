#include <bits/stdc++.h>
#include <set>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main() {
  FASTIO;
  int n, m, k, x, i, ans=0;
  cin >> n >> m >> k;
  vector<int> p(n, 0);
  multiset<int> r;
  for (int i=0; i<n; i++) {
    cin >> p[i];
  }
    while (m--) {
      cin >> x;
      r.insert(x);
    }
    sort(p.begin(), p.end());
    for (int i=0; i<n; i++) {
      auto v = r.lower_bound(p[i]-k);
      if (v!= r.end() && abs(p[i]- *v) <= k) {
        ans++;
        r.erase(v);
      }
    }
    cout << ans;
    return 0;
}