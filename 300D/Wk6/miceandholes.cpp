#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

vector<long long> arr;

long long binarySearch(long long desiredNum, long long h) {
    long long low=0, mid=0, high = h;
    while (low <= high) {
        mid = (low+high)/2;
        if (arr[mid] < desiredNum) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    if (arr[high] < desiredNum) return high;
}

int main() {
    long long a, n, m, ans=0, h;
    vector<long long> mice;
    cin >> n >> m;
    h = m;
    for (long long i=0; i<n; i++) {
        cin >> a;
        mice.push_back(a);
    }
    
    for (long long i=0; i<m; i++) {
        cin >> a;
        arr.push_back(a);
    }
    
    for (long long i=n-1; i>=0; i--) {
        h = binarySearch(mice[i], h-1);
        ans += mice[i] - arr[h];
    }

    cout << ans;
    return 0;
}