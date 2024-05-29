#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

vector<int> cows;
int n;

int calcTime(int stage) {
    priority_queue<int> order;

}

int main() {
    FASTIO;
    int tMax, x, left=0, right, mid, time;
    cin >> n >> tMax;
    for (int i=0; i<n; i++) {
        cin >> x;
        cows.push_back(x);
    }
    right = n;

    while (left < right) {
        mid = (right+left)/2;
        time = calcTime(mid);
        if (mid == tMax) {
            cout << mid;
            return 0;
        }
        else if (mid < tMax) {
            left = mid+1;
        }
        else {
            right = mid;
        }
    }
}