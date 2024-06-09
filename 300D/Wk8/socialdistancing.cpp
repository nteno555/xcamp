#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL long long
using namespace std;

LL n, g, l, m, r, i;
vector<pair<LL, LL>> v;
bool check(){
  LL pos, cow, num;
  for (pos=cow=i=0; i<g; i++) {
    if (pos > v[i].second) continue;
    pos = max(v[i].first, pos);
    num = 1 + (v[i].second - pos)/m;
    cow += num;
    if (cow >= n) return true;
    pos += num * m;
  }
  return false;
}

int main() {
  FASTIO;
  cin >> n >> g;
  for (LL i=0; i<g; i++) {
    cin >> l >> r;
    v.emplace_back(make_pair(l, r));
  }
  sort(v.begin(), v.end());
  l = 0, r=v[g-1].second;
  while (r >= l) {
    m = (l+r)/2;
    if (check()) l=m+1;
    else r=m-1;
  }
  cout << r;
  return 0;
}