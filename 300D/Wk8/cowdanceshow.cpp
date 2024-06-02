#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, tMax, l, r, m, i, t;
vector<int> times;

bool check() {
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i=0; i<m; i++) {
    q.push(times[i]);
  }
  for (int i=m; i<n; i++) {
    if (q.top() + times[i] > tMax) return false;
    q.push(q.top() + times[i]);
    q.pop();
  }
  return true;
}
int main() {
  FASTIO;
  cin >> n >> tMax;
  for (int i=0; i<n; i++) {
    cin >> t;
    times.emplace_back(t);
  }
  l=1, r=n;
  while (r>=l) {
    m = (l+r)/2;
    if (!check()) {
      l = m+1;
    }
    else {
      r = m-1;
    }
  }
  cout << l;
  return 0;
}