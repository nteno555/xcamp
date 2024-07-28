#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, a[610], pre[610], f[610][610];

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
    a[i+n] = a[i];
  }
  memset(f, 0x3f, sizeof(f));
  for (int i=1; i<=n*2; i++) {
    pre[i] = pre[i-1] + a[i];
    f[i][i] = 0;
  }
  for (int len=2; len<=n; len++) {
    for (int i=1, j=i+len-1; j<=n*2; i++, j++) {
      for (int k=i; k<j; k++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + pre[j] - pre[i-1]);
      }
    }
  }

  int res = 2E9;
  for (int i=1; i<=n; i++) {
    res = min(res, f[i][i+n-1]);
  }
  cout << res;
}