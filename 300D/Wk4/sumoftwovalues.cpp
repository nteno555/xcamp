#include <bits/stdc++.h>
#include <vector>
// #include <fstream>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, arr[200001];

int findIndex(int num, int notEquals) {
    for (int i=0; i<n; i++) {
        if (num==arr[i] && i!= notEquals) {
            return i;
        }
    }
    return -1;
}

int main() {FASTIO;
  int k, p1=0, p2, ans=0;
  vector<int> v;

  cin >> n >> k;
  p2 = n-1;

  for (int i=0; i<n; i++) {
    cin >> arr[i];
    v.push_back(arr[i]);
  }

  sort(v.begin(), v.end());
  
  while (p1<p2) {
    if (v[p1]+v[p2] == k) {
        p1 = findIndex(v[p1], -1);
        cout << p1+1 << ' ' << findIndex(v[p2], p1)+1;
        return 0;
    }
    else if (v[p1]+v[p2] > k) p2--;
    else p1++;
  }
  
  cout << "IMPOSSIBLE";
}