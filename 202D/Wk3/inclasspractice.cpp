#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    int n, k, temp, sum=0, curCount=0, ans=0;
    cin >> n >> k;
    
    for (int i=0; i<n; i++) {
        cin >> temp;
        
        sum = sum + temp;
        curCount++;
        q.push(temp);

        if (sum >= k) {
            if (sum == k) ans = max(ans, curCount);
            sum = sum - q.front();
            q.pop();
            curCount--;
        }
        ans = max(ans, curCount);
    }
    
    cout << ans;
}

// int n, k, arr[100], ans=0;

// int check(int start) {
//     int temp = k, count;
//     for (int i=start; i<n; i++) {
//         count++;
//         k = k - arr[i];
//         if (k <= 0) {
//             return count;
//         }
//     }
// }

// int main() {
//     cin >> n >> k;

//     for (int i=0; i<n; i++) {
//         cin >> arr[i];
//     }

//     for (int i=0; i<n; i++) {
//         ans = max(ans, check(i));
//     }

//     cout << ans;
// }