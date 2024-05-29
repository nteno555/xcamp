#include <bits/stdc++.h>
#include <vector>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define ll long long

ll n, arr[5001];

ll findIndex(ll num) {
    for (ll i=0; i<n; i++) {
        if (arr[i]==num) {
            arr[i] = -LLONG_MAX;
            return i;
        }
    }
    return -1;
}

int main() { FASTIO;
    ll desiredSum, j, k;
    vector<ll> v;
    cin >> n >> desiredSum;

    for (ll i=0; i<n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());


    for (ll i=0; i<n; i++){
        j = i+1;
        k = n-1;
        while (j<k) {
            if (v[i] + v[j] + v[k] == desiredSum) {
                cout << findIndex(v[i])+1 << ' ' << findIndex(v[j])+1 << ' ' << findIndex(v[k])+1;
                return 0;
            }
            else if (v[i] + v[j] + v[k] < desiredSum) {
                j++;
            }
            else {
                k--;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}