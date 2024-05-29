#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

vector<double> ropes;
int n;

int calcSegs(double len) {
    int segs, ans=0;
    for (int i=0; i<n; i++) {
        segs = ropes[i]/len;
        ans += segs;
    }
    return ans;
}

int main() {
    int k, cur;
    double x, right=0, left=0.0, mid;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> x;
        ropes.push_back(x);
        right += x;
    }
    right = ceil((right/k) * 100.0)/100.0;
    while (left<=right) {
        mid = ceil(((left+right)/2;) * 100.0)/100.0;
        cur = calcSegs(mid);
        if (cur >= k) {
            right = mid - 0.01;
        }
        else {
            left = mid - 0.01;
        }
    }
    cout << right;
    return 0;
}