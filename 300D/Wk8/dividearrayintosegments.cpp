#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL long long
using namespace std;

LL n, segments;
vector<LL> nums;

bool divide(LL maxSum) {
    LL curSum = 0, curSegs = 1;
    for (LL i=0; i<n; i++) {
        if (nums[i] > maxSum) return false;
        if (curSum + nums[i] > maxSum) {
            curSum = nums[i];
            curSegs++;
        }
        else {
            curSum += nums[i];
        }

        if (curSegs > segments) return false;
    }
    if (curSegs > segments) return false;
    return true;
}

int main() {FASTIO;
    LL temp, left=0, right=0, mid;
    bool segs;
    cin >> n >> segments;
    for (LL i=0; i<n; i++) {
        cin >> temp;
        left = max(temp, left);
        right += temp;
        nums.push_back(temp);
    }
    while (left <= right) {
        mid = (left + right)/2;
        segs = divide(mid);
        if (segs) {
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    cout << left;
}