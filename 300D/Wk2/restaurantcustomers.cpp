#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int main() { FASTIO;
    int n, start, end, curCustomer = 0, ans=0;
    vector<pair<int, int>> steps;

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> start >> end;

        steps.push_back({start, 1});
        steps.push_back({end, -1});
    }

    sort(steps.begin(), steps.end());

    for (auto i: steps) {
        curCustomer += i.second;
        ans = max(ans, curCustomer);
    }

    cout << ans;

    return 0;
}