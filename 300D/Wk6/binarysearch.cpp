#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
  int n, left, right, desiredNum, middle, arr[100001];
  cin >> n;
  for (int i=1; i<=n; i++) cin >> arr[i];
  while (cin >> desiredNum) {
    middle = left = 1, right = n;
    while (right >= left) {
      middle = (left + right)/2;
      if (arr[middle] < desiredNum) left = middle+1;
      else right = middle-1;
    }
    cout << (desiredNum == arr[left]) * left << ' ';
  }
  return 0;      
}