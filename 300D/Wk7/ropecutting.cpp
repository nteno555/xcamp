#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int seg(vector<int> &v, int c1) {
  int collected = 0;
  for (int i: v) {
    collected += i >= c1 ? i / c1 : 0;
  }
  return collected;
}

int main() {
  int n, len;
  float t;
  cin >> n >> len;
  vector<int> ropes;
  for (int i=0; i<n; i++) {
    cin >> t;
    ropes.push_back((int)(t*100));
  }
  sort(ropes.begin(), ropes.end());
  int l=0, r=ropes[n-1];
  while(l<r) {
    int m = (l+r)/2;
    if (seg(ropes, m) >= len) {
      l = m+1;
    }
    else {
      r = m;
    }
  }
  cout << fixed << setprecision(2) << (float(r-1)/100);
}