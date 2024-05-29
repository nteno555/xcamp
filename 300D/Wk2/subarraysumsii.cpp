#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
    int n, desiredSum, ans=0, prefix[200001];

    map<int, int> m;

    cin >> n >> desiredSum;

    for (int i=0; i<n; i++) {
        cin >> prefix[i];
        if (i!=0) prefix[i] += prefix[i-1];

        if (prefix[i] == desiredSum) ans++;

        ans += m[prefix[i] - desiredSum];

        if (m.find(prefix[i]) == m.end()) {
            m.insert({prefix[i], 1});
        }
        else {
            m[prefix[i]]++;
        }
    }

    cout << prefix[i];

    return 0;
}