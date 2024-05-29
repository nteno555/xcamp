#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, arr[100001];

int binarySearch(int desiredNum) {
    int low=1, mid = 1, high = n;
    while (low <= high) {
        mid = (low+high)/2;
        if (arr[mid] > desiredNum) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    if (arr[low] > desiredNum) return low;
    else return n+1;
}

int main() {FASTIO;
    int a;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    while (cin >> a) {
        cout << binarySearch(a) << ' ';
    }
}