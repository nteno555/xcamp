#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
    int n, k, a, b;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i=0; i<k; i++) {
        cin >> a >> b;
        v[a-1]++;
        v[b]--;
    }
    for (int i=1; i<n; i++) {
        v[i] += v[i-1];
    }
    
    sort(v.begin(), v.end());
    cout << v[n/2];
    return 0;
}