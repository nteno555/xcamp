#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

long long g, n, i, x, y, t, x2, y2, t2, ans=0;
tuple<long long, long long, long long> graze[100000];

static inline bool check(long long p) {
  if (p<0 || p>=g) return false;
  tie(t2, x2, y2) = graze[p];
  return ( ((x-x2) * (x-x2) + (y-y2)*(y-y2)) > (t-t2)*(t-t2));
}

int main() {
  cin >> g >> n;
  for (int i=0; i<g; i++) {
    cin >> x >> y >> t;
    graze[i] = {t, x, y};
  }
  sort(graze, graze+g);

  for (int j=0; j<n; j++) {
    cin >> x >> y >> t;
    i = lower_bound(graze, graze+g, make_tuple(t, 0, 0)) - graze;
    if (check(i) || check(i-1)) ans++;
  }

  cout << ans;
  return 0;
}