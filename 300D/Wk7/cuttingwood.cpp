#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

long long n;
vector<long long> trees;

long long calcWood(long long height) {
    long long ans=0, p = upper_bound(trees.begin(), trees.end(), height) - trees.begin();
    for (long long i=p; i<n; i++) {
        ans += trees[i]-height;
    }
    return ans;
}

int main() {FASTIO;
    long long desiredWood, x, j=0;
    cin >> n >> desiredWood;
    for (long long i=0; i<n; i++) {
        cin >> x;
        j = max(j, x);
        trees.push_back(x);
    }
    sort(trees.begin(), trees.end());
    
    long long i=0, mid=0, wood;
    while (i<=j) {
        mid = (i+j)/2;
        wood = calcWood(mid);
        if (wood == desiredWood) {
            cout << mid;
            return 0;
        }
        else if (wood < desiredWood) {
            j = mid-1;
        }
        else {
            i = mid+1;
        }
    }
    cout << j;
    return 0;
}