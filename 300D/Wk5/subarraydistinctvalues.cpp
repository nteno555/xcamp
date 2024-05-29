#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {FASTIO;
    int n, maxDistinct, arr[200001], cur=0, i=0;
    map<int, int> m;
    cin >> n >> maxDistinct;

    for (int j=0; j<n; j++) {
        if (m.find(arr[j])) {
            m[arr[j]]++;
        }
        else {
            m[arr[j]] = 1;
            cur++;
        }

        while (cur > maxDistinct) {
            m[arr[i]]--;
            if (m[arr[i]] == 0) cur--;
            i++;
        }   

        ans += j-i+1;

    }

    cout << ans;
}