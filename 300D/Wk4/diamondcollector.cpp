#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
  int n, k, i, l=1, lMax=0, rMax=0, ans=0;
  cin >> n >> k;
  int r = n;

  vector<int> d(n+1, 0), left(n+1, 0), right(n+1, 0);
  for (int i=0; i<n; i++) {
    cin >> d[i+1];
  }

  sort(d.begin(), d.end());

  for (int i=1; i<n; i++) {
    if (d[i]-d[lp] > k) lp++;
    else lMax++;
    l[i] = lMax;

    if (d[rp]-d[n+1-i] > k) rp--;
    else rmax++;
    r[i] = rMax;
  }

  for (int i=1; i<n-1; i++) {
    ans = max(ans, l[i] + r[n-i]);
  }

  cout << ans;
  return 0;
}