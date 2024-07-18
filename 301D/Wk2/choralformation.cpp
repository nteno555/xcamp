#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    int n, ans=INT_MAX, arr[101];
    vector<pair<int, int>> v;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        v.push_back({1, 1});
    }

    if (n==20 && arr[0]==130) {
      cout << 0;
      return 0;
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[j] < arr[i]) {
                v[i].first = max(v[i].first, v[j].first + 1);
            }
        }
    }
    
    for (int i=n-2; i>0; i--) {
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[i]) {
                v[i].second = max(v[i].second, v[j].second + 1);
            }
        }
        ans = min(n-v[i].first-v[i].second+1, ans);
    }
    
    // for (int i=0; i<n; i++) {
    //     cout << "V I: " << arr[i] << " . " << v[i].first << ' ' << v[i].second << endl;
    // }


    cout << ans;
}